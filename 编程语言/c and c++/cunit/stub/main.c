#include <stdio.h>
#include <stdbool.h>
#include "stub.h"

void f1() {
    printf("f1\n");
    return;
}

void f1_stub() {
    printf("f1_stub\n");
    return;
}

bool distanceof(void* addr, void* addr_stub)
{
    unsigned long long addr_tmp = (unsigned long long)addr;
    unsigned long long addr_stub_tmp = (unsigned long long)addr_stub;
    unsigned int int_addr_tmp = (unsigned int)(addr_tmp >> 32);
    unsigned int int_addr_stub_tmp = (unsigned int)(addr_stub_tmp >> 32);
    if ((int_addr_tmp > 0 && int_addr_stub_tmp > 0) || (int_addr_tmp == 0 && int_addr_stub_tmp == 0))
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main() {

  bool dis = distanceof(f1,f1_stub);
  printf("f1 %p, f1_stub %p, dis %d\n", f1, f1_stub, dis);
  
  stub_init();
  stub_set((void *)f1, (void *)f1_stub);
  f1();
  stub_reset();
  return 0;
}
