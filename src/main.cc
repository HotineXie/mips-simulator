#include "scanner.h"
#include "simulator.h"
#include "memory.h"

#include <iostream>
#include <fstream>

extern void *mem_ptr;
extern void *static_data_ptr;

int main(int argc, char** argv) {
  std::string asmFilePath = argv[1];
  std::string binFilePath = argv[2];
  std::string checkpointFilePath = argv[3];
  std::string ioInFilePath = argv[4];
  std::string ioOutFilePath = argv[5];

  std::ifstream asmCode(asmFilePath);
  std::ifstream binCode(binFilePath);
  std::ifstream checkPoint(checkpointFilePath);
  std::ifstream ioIn(ioInFilePath);
  std::ofstream ioOut(ioOutFilePath, std::ios::trunc);

  *(char *)static_data_ptr = '\n';

  // test dump
  FILE *fp = fopen("dump", "wb");
  fwrite(mem_ptr, 1, 0x600000, fp);
  fclose(fp);
  std::cout << mem_ptr << std::endl;
  std::cout << static_data_ptr << std::endl;
  std::cout << *(int *)static_data_ptr << std::endl; 
  return 0;
}