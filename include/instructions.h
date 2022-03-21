#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#include <iostream>
#include <cstring>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void add(int* rs, int* rt, int *rd);
void addi(int* rs, int* rt, int immediate);
void addu(int* rs, int* rt, int *rd);
void addiu(int* rs, int* rt, int immediate);
void and_instr(int* rs, int* rt, int *rd);
void andi_instr(int* rs, int* rt, int immediate);
void clo(int* rs, int *rd);
void clz(int* rs, int* rd);
void div(int* lo, int* hi, int* rs, int* rt);
void divu(int* lo, int* hi, int* rs, int* rt);
void mult(int* lo, int* hi, int* rs, int* rt);
void multu(int* lo, int* hi, int* rs, int* rt);
void mul(int* lo, int* hi, int* rs, int* rt, int* rd);
void madd(int* lo, int* hi, int* rs, int* rt);
void maddu(int* lo, int* hi, int* rs, int* rt);
void msub(int* lo, int* hi, int* rs, int* rt);
void msubu(int* lo, int* hi, int* rs, int* rt);
void nor(int* rs, int* rt, int* rd);
void or_instr(int* rs, int* rt, int* rd);
void ori(int* rs, int* rt, int immediate);
void sll(int* rt, int* rd, int shamt);
void sllv(int* rs, int* rt, int* rd);
void sra(int* rt, int* rd, int shamt);
void srav(int* rs, int* rt, int* rd);
void srl(int* rt, int* rd, int shamt);
void srlv(int* rs, int* rt, int* rd);
void sub(int* rs, int* rt, int* rd);
void subu(int* rs, int* rt, int* rd);
void xor_instr(int* rs, int*rt, int* rd);
void xori(int* rs, int* rt, int immediate);
void lui(int* rt, int immediate);
void slt(int* rs, int* rt, int* rd);
void sltu(int* rs, int* rt, int* rd);
void slti(int* rs, int* rt, int immediate);
void sltiu(int* rs, int* rt, int immediate);
void beq(int* pc, int* rs, int* rt, int immediate);
void bgez(int* pc, int* rs, int immediate);
void bgezal(int* pc, int* ra, int* rs, int immediate);
void bgtz(int* pc, int* rs, int immediate);
void blez(int* pc, int* rs, int immediate);
void bltz(int* pc, int* rs, int immediate);
void bltzal(int* pc, int* ra, int* rs, int immediate);
void bne(int* pc, int* rs, int* rt, int immediate);
void j(int* pc, int immediate);
void jal(int* pc, int* ra, int immediate);
void jalr(int* pc, int* ra, int* rs, int* rd);
void jr(int* pc, int* rs);
void teq(int* pc, int* rs, int* rt);
void teqi(int* pc, int* rs, int immediate);
void tne(int* pc, int* rs, int* rt);
void tnei(int* pc, int* rs, int immediate);
void tge(int* pc, int* rs, int* rt);
void tgei(int* pc, int* rs, int immediate);
void tgeu(int* pc, int* rs, int* rt);
void tgeiu(int* pc, int* rs, int immediate);
void tlt(int* pc, int* rs, int* rt);
void tlti(int* pc, int* rs, int immediate);
void tltu(int* pc, int* rs, int* rt);
void tltiu(int* pc, int* rs, int immediate);
void lb(char* mem, int* rs, int* rt, int immediate);
void lbu(char* mem, int* rs, int* rt, int immediate);
void lh(char* mem, int* rs, int* rt, int immediate);
void lhu(char* mem, int* rs, int* rt, int immediate);
void lw(char* mem, int* rs, int* rt, int immediate);
void lwl(char* mem, int* rs, int* rt, int immediate);
void lwr(char* mem, int* rs, int* rt, int immediate);
void ll(char* mem, int* rs, int* rt, int immediate);
void sb(char* mem, int* rs, int* rt, int immediate);
void sh(char* mem, int* rs, int* rt, int immediate);
void sw(char* mem, int* rs, int* rt, int immediate);
void swl(char* mem, int* rs, int* rt, int immediate);
void swr(char* mem, int* rs, int* rt, int immediate);
void sc(char* mem, int* rs, int* rt, int immediate);
void mfhi(int* hi, int* rd);
void mflo(int* lo, int* rd);
void mthi(int* hi, int* rs);
void mtlo(int* lo, int* rs);

#endif