#include <iostream>
#include <algorithm>
#include "simulator.h"
#include "instructions.h"

void Simulator::init_regs() {
  zero = regArray + 0;
  at = regArray + 1;
  v0 = regArray + 2;
  v1 = regArray + 3;
  a0 = regArray + 4;
  a1 = regArray + 5;
  a2 = regArray + 6;
  a3 = regArray + 7;
  t0 = regArray + 8;
  t1 = regArray + 9;
  t2 = regArray + 10;
  t3 = regArray + 11;
  t4 = regArray + 12;
  t5 = regArray + 13;
  t6 = regArray + 14;
  t7 = regArray + 15;
  s0 = regArray + 16;
  s1 = regArray + 17;
  s2 = regArray + 18;
  s3 = regArray + 19;
  s4 = regArray + 20;
  s5 = regArray + 21;
  s6 = regArray + 22;
  s7 = regArray + 23;
  t8 = regArray + 24;
  t9 = regArray + 25;
  k0 = regArray + 26;
  k1 = regArray + 27;
  gp = regArray + 28;
  sp = regArray + 29;
  fp = regArray + 30;
  ra = regArray + 31;
  pc = regArray + 32;
  hi = regArray + 33;
  lo = regArray + 34;
  *gp = 0x508000;
  *sp = 0xA00000;
  *fp = 0xA00000;
  *pc = 0x400000;
}

void Simulator::exec_bin_code() {
  int currentInstruction = 0;
  while ((char *)mem_ptr + *pc - 0x400000 < (char *)text_ptr - 1) {
    for (int i=0;i<checkoutPoints.size();i++) {
      if (currentInstruction == checkoutPoints[i]) 
        print_dumps(currentInstruction);
    }
    unsigned int currentCode = *(int  *)((char *)mem_ptr + *pc - 0x400000);
    std::string currentBin = dec_to_bin(currentCode);
    // std::cout << currentBin <<std::endl;
    classify_instruction(currentBin);
    // std::cout << ((char *)mem_ptr + *pc - 0x400000 < (char *)text_ptr - 1)<<std::endl;
    // std::cout << *pc - 0x400000 <<std::endl;
    *pc += 4;
    currentInstruction++;
  }
}

void Simulator::print_dumps(int currentInstruction) {
  std::string memName = "memory_" + std::to_string(currentInstruction) + ".bin";
  FILE *memFp = fopen(memName.c_str(), "wb");
  fwrite(mem_ptr, 1, 0x600000, memFp);
  fclose(memFp);
  std::string regName = "register_" + std::to_string(currentInstruction) + ".bin";
  FILE *regFp = fopen(regName.c_str(), "wb");
  fwrite(regArray, 1, 140, regFp);
  fclose(regFp);
}

std::string Simulator::dec_to_bin(unsigned int dec) {
    std::string binStr;
    while (dec != 0) {
        binStr += ( dec % 2 == 0 ? "0" : "1" );
        dec /= 2;
    }
    while (binStr.size()<32) {
      binStr += '0';
    }
    std::reverse(binStr.begin(), binStr.end());
    return binStr;
}

void Simulator::classify_instruction(std::string currentBin) {
  int opcode = binstr_to_int(currentBin.substr(0,6));
  if (currentBin == "00000000000000000000000000001100") {
    syscall_instr((char *)mem_ptr, v0, a0, a1, a2, data_ptr);
    return;
  }
  if (opcode == 0) {
    int funct = binstr_to_int(currentBin.substr(26, 6));
    int rsOffset = binstr_to_int(currentBin.substr(6, 5));
    int rtOffset = binstr_to_int(currentBin.substr(11, 5));
    int rdOffset = binstr_to_int(currentBin.substr(16, 5));
    int shamt = binstr_to_int(currentBin.substr(21,5));
    int *rs; rs = regArray + rsOffset;
    int *rt; rt = regArray + rtOffset;
    int *rd; rd = regArray + rdOffset;

    switch (funct) {
    case 0x20: 
      add(rs, rt, rd);
      break;
    case 0x21: 
      addu(rs, rt, rd);
      break;
    case 0x24: 
      and_instr(rs, rt, rd);
      break;
    case 0x1a:
      div(lo, hi, rs, rt);
      break;
    case 0x1b:
      divu(lo, hi, rs, rt);
      break;
    case 0x09:
      jalr(pc, ra, rs, rd);
      break;
    case 0x08:
      jr(pc, rs);
      break;
    case 0x10:
      mfhi(hi, rd);
      break;
    case 0x12:
      mflo(lo, rd);
      break;
    case 0x11:
      mthi(hi, rs);
      break;
    case 0x13:
      mtlo(lo, rs);
      break;
    case 0x18:
      mult(lo, hi, rs, rt);
      break;
    case 0x19:
      multu(lo, hi, rs, rt);
      break;
    case 0x27:
      nor(rs, rt, rd);
      break;
    case 0x25:
      or_instr(rs, rt, rd);
      break;
    case 0x00:
      sll(rt, rd, shamt);
      break;
    case 0x04:
      sllv(rs, rt, rd);
      break;
    case 0x2a:
      slt(rs, rt, rd);
      break;
    case 0x2b:
      sltu(rs, rt, rd);
      break;
    case 0x03:
      sra(rt, rd, shamt);
      break;
    case 0x07:
      srav(rs, rt, rd);
      break;
    case 0x02:
      srl(rt, rd, shamt);
      break;
    case 0x06:
      srlv(rs, rt, rd);
      break;
    case 0x22:
      sub(rs, rt, rd);
      break;
    case 0x23:
      subu(rs, rt, rd);
      break;
    case 0x26:
      xor_instr(rs, rt, rd);
      break;
    default:
      break;
    }
  }

  else if (opcode == 2 || opcode == 3) {
    int target = binstr_to_int(currentBin.substr(6,26));
    if (opcode == 2) {
      j(pc, target);
    }
    if (opcode == 3) {
      jal(pc, ra, target);
    }
  }

  else{
    int rsOffset = binstr_to_int(currentBin.substr(6, 5));
    int rtOffset = binstr_to_int(currentBin.substr(11, 5));
    int imm = binstr_to_int(currentBin.substr(16,16));
    if (imm > 32767) imm = imm - 65536;
    int *rs; rs = regArray + rsOffset;
    int *rt; rt = regArray + rtOffset;
    switch (opcode) {
      case 0x08:
        addi(rs, rt, imm);
        break;
      case 0x09:
        addiu(rs, rt, imm);
        break;
      case 0x0c:
        andi_instr(rs, rt, imm);
        break;
      case 0x04:
        beq(pc, rs, rt, imm);
        break;
      case 0x01:
        if (rtOffset == 1) bgez(pc, rs, imm);
        if (rtOffset == 0) bltz(pc, rs, imm);
        break;
      case 0x07:
        bgtz(pc, rs, imm);
        break;
      case 0x06:
        blez(pc, rs, imm);
        break;
      case 0x05:
        bne(pc, rs, rt, imm);
        break;
      case 0x20:
        lb((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x24:
        lbu((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x21:
        lh((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x25:
        lhu((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x0F:
        lui(rt, imm);
        break;
      case 0x23:
        lw((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x0d:
        ori(rs, rt, imm);
        break;
      case 0x28:
        sb((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x0a:
        slti(rs, rt, imm);
        break;
      case 0x0b:
        sltiu(rs, rt, imm);
        break;
      case 0x29:
        sh((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x2b:
        sw((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x0e:
        xori(rs, rt, imm);
        break;
      case 0x22:
        lwl((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x26:
        lwr((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x2a:
        swl((char *)mem_ptr, rs, rt, imm);
        break;
      case 0x2e:
        swr((char *)mem_ptr, rs, rt, imm);
        break;
    default:
      break;
    }
  }
}

int Simulator::binstr_to_int(std::string binStr) {
  int result = 0;
  for (int i=0;i<binStr.size();i++) {
    int tmp = (binStr[binStr.size()-1-i]-'0');
    tmp = tmp << i;
    result += tmp;
  }
  return result;
}

void Simulator::syscall_instr(char* mem, int* v0, int* a0, int* a1, int* a2, void* data_ptr) {
  if (*v0 == 1) {
    fprintf(outFile, "%d", *a0);
    // printInfos.push_back(std::to_string(*a0));
    return;
  }
  if (*v0 == 4) {
    int real_addr = *a0 - 0x400000;
    char *temp = mem + real_addr;
    fwrite(temp, std::strlen(temp), 1, outFile);
    // printInfos.push_back(temp);
    return;
  }
  if (*v0 == 5) {
    *v0 = std::stoi(readInfos[0]);
    for (int i=0;i<readInfos.size()-1;i++) {
      readInfos[i] = readInfos[i+1];
    }
    return;
  }
  if (*v0 == 8) {
    int real_addr = *a0 - 0x400000;
    char temp[readInfos[0].size()];
    strcpy(temp, readInfos[0].c_str());
    memcpy(mem + real_addr, temp, *a1);
    return;
  }
  if (*v0 == 9)
  {
    *v0 = (char *)data_ptr - mem + 0x400000;
    data_ptr = (char *)data_ptr + *a0;
    return;
  }
  if (*v0 == 10) {
    exit(0);
  }
  if (*v0 == 11) {
    char temp = *a0;
    fprintf(outFile, "%c", *a0);
    // fwrite(temp, sizeof(*temp), 1, outFile);
    // printInfos.push_back(std::to_string(temp));
    return;
  }
  if (*v0 == 12) {
    *(char *)v0 = readInfos[0][0];
    for (int i=0;i<readInfos.size()-1;i++) {
      readInfos[i] = readInfos[i+1];
    }
    return;
  }
  if (*v0 == 13) {
    int real_addr = *a0 - 0x400000;
    *v0 = open(mem + real_addr, *a1, *a2);
    return;
  }
  if(*v0 == 14) {      
    int real_addr = *a1 - 0x400000;
    *v0 = read(*a0, mem + real_addr, *a2);
    return;
  }

  if (*v0 == 15) {
    int real_addr = *a1 - 0x400000;
    *v0 = write(*a0, mem + real_addr, *a2);
    return;
  }

  if (*v0 == 16) {
    close(*a0);
  }

  if (*v0 == 17) {
    exit(*a0);
  }
}
