#include <iostream>

void *mem_ptr = (void *)malloc(0x600000);
void *static_data_ptr = (void *)((char *)mem_ptr + 0x100000);
