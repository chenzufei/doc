#ifndef __STUB_H__
#define __STUB_H__

#include <stdio.h>

#define CODESIZE 5U

struct func_stub {
  void *fn;
  unsigned char code_buf[CODESIZE];
};

void stub_init();
void stub_set(void *fn, void *fn_stub);
void stub_reset();
#endif
