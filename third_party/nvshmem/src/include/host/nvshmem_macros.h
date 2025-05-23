
#ifndef _NVSHMEM_MACROS_H_
#define _NVSHMEM_MACROS_H_

#include <cuda_runtime.h>

#ifdef __CUDA_ARCH__
#ifdef NVSHMEMI_HOST_ONLY
#define NVSHMEMI_HOSTDEVICE_PREFIX __host__
#else
#define NVSHMEMI_HOSTDEVICE_PREFIX __host__ __device__
#endif
#else
#define NVSHMEMI_HOSTDEVICE_PREFIX
#endif

#if defined NVSHMEM_BITCODE_APPLICATION
#undef NVSHMEMI_HOSTDEVICE_PREFIX
#define NVSHMEMI_HOSTDEVICE_PREFIX __host__ __device__ __attribute__((always_inline))
#endif

#endif
