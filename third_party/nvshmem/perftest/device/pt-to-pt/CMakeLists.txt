nvshmem_add_perftest(shmem_atomic_bw.cu)
nvshmem_add_perftest(shmem_atomic_latency.cu)
nvshmem_add_perftest(shmem_atomic_ping_pong_latency.cu)
nvshmem_add_perftest(shmem_g_bw.cu)
nvshmem_add_perftest(shmem_g_latency.cu)
nvshmem_add_perftest(shmem_get_bw.cu)
nvshmem_add_perftest(shmem_get_latency.cu)
nvshmem_add_perftest(shmem_p_bw.cu)
nvshmem_add_perftest(shmem_p_latency.cu)
nvshmem_add_perftest(shmem_p_ping_pong_latency.cu)
nvshmem_add_perftest(shmem_put_atomic_ping_pong_latency.cu)
nvshmem_add_perftest(shmem_put_bw.cu)
nvshmem_add_perftest(shmem_put_latency.cu)
nvshmem_add_perftest(shmem_put_ping_pong_latency.cu)
nvshmem_add_perftest(shmem_put_signal_ping_pong_latency.cu)
nvshmem_add_perftest(shmem_signal_ping_pong_latency.cu)
nvshmem_add_perftest(shmem_st_bw.cu)

if(NVSHMEM_BUILD_BITCODE_LIBRARY)
    nvshmem_add_cubin_perftest(shmem_atomic_bw.cu)
    nvshmem_add_cubin_perftest(shmem_atomic_latency.cu)
    nvshmem_add_cubin_perftest(shmem_atomic_ping_pong_latency.cu)
    nvshmem_add_cubin_perftest(shmem_g_latency.cu)
    nvshmem_add_cubin_perftest(shmem_get_latency.cu)
    nvshmem_add_cubin_perftest(shmem_p_latency.cu)
    nvshmem_add_cubin_perftest(shmem_p_ping_pong_latency.cu)
    nvshmem_add_cubin_perftest(shmem_put_atomic_ping_pong_latency.cu)
    nvshmem_add_cubin_perftest(shmem_put_latency.cu)
    nvshmem_add_cubin_perftest(shmem_put_ping_pong_latency.cu)
    nvshmem_add_cubin_perftest(shmem_put_signal_ping_pong_latency.cu)
    nvshmem_add_cubin_perftest(shmem_signal_ping_pong_latency.cu)
endif()
