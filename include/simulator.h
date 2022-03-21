#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <vector>
#include <string>
#include <map>
#include "mem_and_reg.h"

class Simulator {
 public:
  void init_regs();
  void exec_bin_code();
  std::vector<int> checkoutPoints;
  std::vector<std::string> readInfos;
  std::vector<std::string> printInfos;

 private:
  std::string dec_to_bin(unsigned int dec);
  void classify_instruction(std::string currentBin);
  int binstr_to_int(std::string binStr);
  void print_dumps(int currentInstruction);
  void syscall_instr(char* mem, int* v0, int* a0, int* a1, int* a2, void* data_ptr);
  int readCounter = 0;
};

#endif