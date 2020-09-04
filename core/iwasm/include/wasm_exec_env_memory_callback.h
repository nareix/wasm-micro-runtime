#ifndef _WASM_EXEC_ENV_MEMORY_CALLBACK_H
#define _WASM_EXEC_ENV_MEMORY_CALLBACK_H

#include <stdint.h>

#define PTR_EXT_SET_BIT (1UL<<31)
#define PTR_EXT_MASK (3UL<<29)
#define PTR_EXT_VALUE_MASK ((1UL<<29)-1)
#define PTR_EXT_TYPE_HOST_STACK (0UL<<29)
#define PTR_EXT_TYPE_GLOBAL     (1UL<<29)
#define PTR_EXT_TYPE_FRAME_SP   (2UL<<29)

typedef struct {
    void *host_stack_base;
    uint8_t *stack_bottom;
    uint32_t rev_sp;
    void *userdata;
    int (*cb_memmove)(void *exec_env, uint32_t dst, int ndst, uint32_t src, int nsrc);
    int (*cb_memset)(void *exec_env, uint32_t dst, int val, int len);
    int (*cb_mem_get_size)(void *exec_env, int *size);
} WASMExecEnvMemoryCallback;

#endif
