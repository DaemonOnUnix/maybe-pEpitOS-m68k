#include <stdint.h>

extern int main();

const uint32_t ivt_start[0x400/4] __attribute__((section(".ivt")))  = {0, &main};
