#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <errno.h>
#include <limits.h>
#include <sys/mman.h>
#include "stub.h"

/* fixme: 需要考虑长跳转场景 */

long pagesize = 4096;
struct func_stub stub;

static inline void *pageof(const void* p) {
  return (void *)((unsigned long)p & ~(pagesize - 1));
}

void set_mprotect(void *fn, bool write) {
  int prot = PROT_READ | PROT_EXEC;

  if (write) {
    prot = prot | PROT_WRITE;
  }

  if (-1 == mprotect(pageof(fn), pagesize, prot)) {
    perror("mprotect to fn faild");
    exit(errno);
  }

  return;
}

void stub_init() {
  pagesize = sysconf(_SC_PAGE_SIZE);
  printf("page size %u\n", pagesize);
  return;
}

void stub_set(void *fn, void *fn_stub) {
  /* 记录函数地址 */
  stub.fn = fn;
  memcpy(stub.code_buf, fn, CODESIZE);
  
  /* 设置fn所在page可写 */
  set_mprotect(fn, true);
  /* 修改函数内存地址，通过jump指令跳转到stub函数 */
  *(unsigned char *)fn = (unsigned char)0xE9;
  *(unsigned int *)((unsigned char *)fn + 1) = (unsigned char *)fn_stub - (unsigned char *)fn - CODESIZE;
  
  /* 设置fn所在page只读 */
  set_mprotect(fn, false);
  return;
}

void stub_reset() {
  /* 设置fn所在page可写 */
  set_mprotect(stub.fn, true);
  /* 还原函数地址 */
  memcpy(stub.fn, stub.code_buf, CODESIZE);
  /* 设置fn所在page只读 */
  set_mprotect(stub.fn, false);
  return;
}
