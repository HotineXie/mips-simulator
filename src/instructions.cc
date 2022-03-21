#include "instructions.h"

void add(int* rs, int* rt, int *rd) {
    *rd = *rs + *rt;
}

void addi(int* rs, int* rt, int immediate) {
  *rt = *rs + immediate;
}

void addu(int* rs, int* rt, int *rd) {
    *rd = *rs + *rt;
}

void addiu(int* rs, int* rt, int immediate) {
    *rt = *rs + immediate;
}

void and_instr(int* rs, int* rt, int *rd) {
    *rd = *rs & *rt;
}

void andi_instr(int* rs, int* rt, int immediate) {
    *rt = *rs & immediate;
}

void mfhi(int* hi, int* rd) {
  *rd = *hi;
}

void mflo(int* lo, int* rd) {
  *rd = *lo;
}

void mthi(int* hi, int* rs) {
  *hi = *rs;
}

void mtlo(int* lo, int* rs) {
  *lo = *rs;
}

void clo(int* rs, int *rd) 
{
    int temp = 32;
    for (int i = 0; i < 32; i++)
        if (((1 << i) & *rs) == 0)
            temp--;

    *rd = temp;
}

void clz(int* rs, int* rd)
{
    int temp = 0;
    for (int i = 0; i < 32; i++)
        if (((1 << i) & *rs) == 0)
            temp++;

    *rd = temp;
}

void div(int* lo, int* hi, int* rs, int* rt)
{
    *lo = *rs / *rt;
    *hi = *rs % *rt;
}

void divu(int* lo, int* hi, int* rs, int* rt)
{
    *lo = unsigned(*rs) / unsigned(*rt);
    *hi = unsigned(*rs) % unsigned(*rt);
}

void mult(int* lo, int* hi, int* rs, int* rt)
{
    long long temp = *rs * *rt;
    *lo = temp;
    *hi = temp >> 32;
}

void multu(int* lo, int* hi, int* rs, int* rt)
{
    long long temp = unsigned(*rs) * unsigned(*rt);
    *lo = temp;
    *hi = temp >> 32;
}

void mul(int* lo, int* hi, int* rs, int* rt, int* rd)
{
    *rd = *rs * *rt;
    *lo = 0; *hi = 0;
}

void madd(int* lo, int* hi, int* rs, int* rt)
{
    long long temp = *rs * *rt;
    long long l_hi = *hi;
    temp += *lo;
    temp += (l_hi << 32);

    *lo = temp;
    *lo = temp >> 32;
}

void maddu(int* lo, int* hi, int* rs, int* rt)
{
    long long temp = unsigned(*rs) * unsigned(*rt);
    long long l_hi = *hi;
    temp += *lo;
    temp += (l_hi << 32);

    *lo = temp;
    *lo = temp >> 32;
}

void msub(int* lo, int* hi, int* rs, int* rt)
{
    long long temp = *rs * *rt;
    long long l_hi = *hi;
    temp -= *lo;
    temp -= (l_hi << 32);

    *lo = temp;
    *lo = temp >> 32;
}

void msubu(int* lo, int* hi, int* rs, int* rt)
{
    long long temp = unsigned(*rs) * unsigned(*rt);
    long long l_hi = *hi;
    temp -= *lo;
    temp -= (l_hi << 32);

    *lo = temp;
    *lo = temp >> 32;
}

void nor(int* rs, int* rt, int* rd)
{
    *rd = ~(*rs | *rt);
}

void or_instr(int* rs, int* rt, int* rd)
{
    *rd = *rs | *rt;
}

void ori(int* rs, int* rt, int immediate)
{
    *rt = *rs | immediate;
}

void sll(int* rt, int* rd, int shamt)
{
    *rd = *rt << shamt;
}

void sllv(int* rs, int* rt, int* rd)
{
    *rd = *rt << *rs;
}

void sra(int* rt, int* rd, int shamt)
{
    *rd = *rt >> shamt;
}

void srav(int* rs, int* rt, int* rd)
{
    *rd = *rt >> *rs;
}

void srl(int* rt, int* rd, int shamt)
{
    *rd = (unsigned)(*rt) >> shamt;
}

void srlv(int* rs, int* rt, int* rd)
{
    *rd = (unsigned)(*rt) >> *rs;
}

void sub(int* rs, int* rt, int* rd)
{
    *rd = *rs - *rt;
}

void subu(int* rs, int* rt, int* rd)
{
    *rd = *rs - *rt;
}

void xor_instr(int* rs, int* rt, int* rd)
{
    *rd = *rs ^ *rt;
}

void xori(int* rs, int* rt, int immediate)
{
    *rt = *rs ^ immediate;
}

void lui(int* rt, int immediate)
{
    *rt = immediate << 16;
}

void slt(int* rs, int* rt, int* rd)
{
    *rd = (*rs < *rt);
}

void sltu(int* rs, int* rt, int* rd)
{
    *rd = (unsigned(*rs) < unsigned(*rt));
}

void slti(int* rs, int* rt, int immediate)
{
    *rt = *rs < immediate;
}

void sltiu(int* rs, int* rt, int immediate)
{
    *rt = (unsigned(*rs) < unsigned(immediate));
}

void beq(int* pc, int* rs, int* rt, int immediate)
{
    if (*rs == *rt)
    {
        *pc += immediate << 2;
    }
}

void bgez(int* pc, int* rs, int immediate)
{
    if (*rs >= 0)
    {
        *pc += immediate << 2;
    }
}

void bgezal(int* pc, int* ra, int* rs, int immediate) {
    *ra = *pc;
    if (*rs >= 0)
    {
        *pc += immediate << 2;
    }
}

void bgtz(int* pc, int* rs, int immediate)
{
    if (*rs > 0)
    {
        *pc += immediate << 2;
    }
}

void blez(int* pc, int* rs, int immediate)
{
    // std::cout << *pc << std::endl;
    if (*rs <= 0)
    {
        *pc += immediate << 2;
    }
    // std::cout << *pc << std::endl;
}

void bltz(int* pc, int* rs, int immediate)
{
    if (*rs < 0)
    {
        *pc += immediate << 2;
    }
}

void bltzal(int* pc, int* ra, int* rs, int immediate)
{
    *ra = *pc;
    if (*rs < 0)
    {
        *pc += immediate << 2;
    }
}

void bne(int* pc, int* rs, int* rt, int immediate)
{
    if (*rs != *rt)
    {
        *pc += immediate << 2;
    }
}

void j(int* pc, int immediate)
{
    immediate = immediate << 2;
    immediate += (*pc & 0xf0000000);
    *pc = immediate - 4;
}

void jal(int* pc, int* ra, int immediate)
{
    *ra = *pc;
    immediate = immediate << 2;
    immediate += (*pc & 0xf0000000);
    *pc = immediate - 4;
}

void jalr(int* pc, int* ra, int* rs, int* rd)
{
    if (*rs == 0)
        *ra = *pc;
    else
        *rd = *pc;
    
    *pc = *rs;
}

void jr(int* pc, int* rs)
{
    *pc = *rs;
}

void lb(char* mem, int* rs, int* rt, int immediate)
{
    int real_addr = *rs - 0x400000 + immediate;
    *rt = mem[real_addr];
}

void lbu(char* mem, int* rs, int* rt, int immediate)
{
    int real_addr = *rs - 0x400000 + immediate;
    *rt = (unsigned char)mem[real_addr];
}

void lh(char* mem, int* rs, int* rt, int immediate)
{
    int16_t temp;
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(&temp, mem + real_addr, 2);
    *rt = temp;
}

void lhu(char* mem, int* rs, int* rt, int immediate)
{
    int16_t temp;
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(&temp, mem + real_addr, 2);
    *rt = (unsigned short)(temp);
}

void lw(char* mem, int* rs, int* rt, int immediate)
{
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(rt, mem + real_addr, 4);
}

void lwl(char* mem, int* rs, int* rt, int immediate)
{
    int temp;
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(&temp, mem + real_addr, 4);
    *rt = *rt & 0x0000ffff;
    *rt += (temp & 0xffff0000);
}

void lwr(char* mem, int* rs, int* rt, int immediate)
{
    int temp;
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(&temp, mem + real_addr, 4);
    *rt = *rt & 0xffff0000;
    *rt += (temp & 0x0000ffff);
}

void ll(char* mem, int* rs, int* rt, int immediate)
{
    int temp;
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(&temp, mem + real_addr, 4);
    *rt = temp;
}

void sb(char* mem, int* rs, int* rt, int immediate)
{
  int8_t temp = *rt & 0x000000ff;
  int real_addr = *rs - 0x400000 + immediate;
  memcpy(mem + real_addr, &temp, 1);
}

void sh(char* mem, int* rs, int* rt, int immediate)
{
    int16_t temp = *rt & 0x0000ffff;
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(mem + real_addr, &temp, 2);
}

void sw(char* mem, int* rs, int* rt, int immediate)
{
  int real_addr = *rs - 0x400000 + immediate;
  memcpy(mem + real_addr, rt, 4);
}

void swl(char* mem, int* rs, int* rt, int immediate)
{
  void *real_addr;
  real_addr = mem + *rs + immediate - 0x400000;
  memcpy(real_addr, rt, 2);
}

void swr(char* mem, int* rs, int* rt, int immediate)
{
    int16_t temp = *rt & 0x0000ffff;
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(mem + real_addr, &temp, 2);
}

void sc(char* mem, int* rs, int* rt, int immediate)
{
    int real_addr = *rs - 0x400000 + immediate;
    memcpy(mem + real_addr, rt, 4);
}
