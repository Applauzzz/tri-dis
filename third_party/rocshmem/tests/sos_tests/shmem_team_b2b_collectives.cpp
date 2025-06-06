/*  Copyright (c) 2019 Intel Corporation. All rights reserved.
 *  This software is available to you under the BSD license below:
 *
 *      Redistribution and use in source and binary forms, with or
 *      without modification, are permitted provided that the following
 *      conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>

#include <rocshmem/rocshmem.hpp>

using namespace rocshmem;

#define NITERS 100
#define NELEMS 10

/*
#define TEST_B2B_COLLECTIVE(NAME, ROUTINE, ...) \
    do { \
        if (me == 0) printf("%s... ", NAME); \
        int i; \
        for (i = 0; i < NITERS; i++) { \
            errors += ROUTINE(__VA_ARGS__); \
        } \
        error_check(&errors, &total_errors, NAME, me); \ } while (0)

static void error_check(int *errors, int *total_errors, char *routine, int me) {
    if (*errors == 0) {
        if (me == 0) printf("passed.\n");
    } else {
        printf("%s error on PE %d\n", routine, me);
        *total_errors += *errors;
        *errors = 0;
    }
    return;
}
*/

#define TEST_B2B_COLLECTIVE(NAME, ROUTINE, ...)   \
  do {                                            \
    if (me == 0) printf("%s... ", NAME);          \
    int i;                                        \
    for (i = 0; i < NITERS; i++) {                \
      ROUTINE(__VA_ARGS__);                       \
    }                                             \
    if (me == 0) printf("Done with %s.\n", NAME); \
  } while (0)

int main(void) {
  int errors = 0, total_errors = 0;
  rocshmem_init();
  int me = rocshmem_my_pe();

  long *dest = (long *)rocshmem_malloc(NELEMS * sizeof(long));
  long *src = (long *)rocshmem_malloc(NELEMS * sizeof(long));

  size_t i;
  for (i = 0; i < NELEMS; i++) {
    src[i] = me;
  }

  TEST_B2B_COLLECTIVE("broadcast", rocshmem_ctx_long_broadcast,
                      ROCSHMEM_CTX_DEFAULT, ROCSHMEM_TEAM_WORLD, dest, src,
                      NELEMS, 0);
  TEST_B2B_COLLECTIVE("reduce", rocshmem_ctx_long_sum_to_all,
                      ROCSHMEM_CTX_DEFAULT, ROCSHMEM_TEAM_WORLD, dest, src,
                      NELEMS);
  // TEST_B2B_COLLECTIVE("collect", rocshmem_long_collect, SHMEM_TEAM_WORLD,
  // dest, src, NELEMS); TEST_B2B_COLLECTIVE("fcollect", rocshmem_long_fcollect,
  // SHMEM_TEAM_WORLD, dest, src, NELEMS); TEST_B2B_COLLECTIVE("alltoall",
  // rocshmem_long_alltoall, SHMEM_TEAM_WORLD, dest, src, NELEMS);
  // TEST_B2B_COLLECTIVE("alltoalls", rocshmem_long_alltoalls,
  // SHMEM_TEAM_WORLD, dest, src, 1, 1, NELEMS);

  rocshmem_free(dest);
  rocshmem_free(src);

  rocshmem_finalize();
  return total_errors;
}
