/**
 * Architecture-specific declarations & definitions.
 *
 * Author: Rob Lyerly <rlyerly@vt.edu>
 * Date: 5/27/2016
 */

#ifndef _ARCH_H
#define _ARCH_H

#include <elf.h>
#include "arch_common.h"

/*
 * Because we don't generate call site metadata for musl, we hardcode an offset
 * from the beginning of "__libc_start_main" and "start" in order to calculate
 * their return addresses on different architectures.
 */
#define START_MAIN_OFF_AARCH64 0x68
#define START_MAIN_OFF_X86_64 0x4f
#define START_THREAD_OFF_AARCH64 0x7c
#define START_THREAD_OFF_X86_64 0x89

/**
 * Return address offset from the start of "__libc_start_main".
 * @param arch the architecture
 * @return the return address offset (in bytes) from the start of
 *         "__libc_start_main"
 */
static inline uint64_t main_start_offset(uint16_t arch)
{
  switch(arch) {
  case EM_X86_64: return START_MAIN_OFF_X86_64;
  case EM_AARCH64: return START_MAIN_OFF_AARCH64;
  default: return 0;
  }
}

/**
 * Return address offset from the start of "start".
 * @param arch the architecture
 * @return the return address offset (in bytes) from the start of "start"
 */
static inline uint64_t thread_start_offset(uint16_t arch)
{
  switch(arch) {
  case EM_X86_64: return START_THREAD_OFF_X86_64;
  case EM_AARCH64: return START_THREAD_OFF_AARCH64;
  default: return 0;
  }
}

#endif /* _ARCH_H */

