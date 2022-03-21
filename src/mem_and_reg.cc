#include "mem_and_reg.h"

void *mem_ptr = (void *)malloc(0x600000);
void *text_ptr = mem_ptr;
void *static_data_ptr = (void *)((char *)mem_ptr + 0x100000);
void *data_ptr = static_data_ptr;

int regArray[35] = {0};
int *zero; // 0
int *at; // 1
int *v0; // 2
int *v1; // 3
int *a0; // 4
int *a1; // 5 
int *a2; // 6
int *a3; // 7
int *t0; // 8
int *t1; // 9
int *t2; // 10
int *t3; // 11
int *t4; // 12
int *t5; // 13
int *t6; // 14
int *t7; // 15
int *s0; // 16
int *s1; // 17
int *s2; // 18
int *s3; // 19
int *s4; // 20
int *s5; // 21
int *s6; // 22
int *s7; // 23
int *t8; // 24
int *t9; // 25
int *k0; // 26
int *k1; // 27
int *gp; // 28
int *sp; // 29
int *fp; // 30
int *ra; // 31
int *pc; // 32
int *hi; // 33
int *lo; // 34
