#include "scanner.h"
#include "simulator.h"
#include "mem_and_reg.h"

#include <iostream>
#include <fstream>

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
  // std::ofstream ioOut(ioOutFilePath, std::ios::trunc);
  FILE *outFile = fopen(ioOutFilePath.c_str(), "w");

  std::string currentLine;
  Scanner MipsScanner;
  Simulator MipsSimulator;

  while (getline(asmCode, currentLine)) {
    MipsScanner.asmCodes.push_back(currentLine);
  }
  while (getline(binCode, currentLine)) {
    MipsScanner.binCodes.push_back(currentLine);
  }
  while (getline(checkPoint, currentLine)) {
    MipsSimulator.checkoutPoints.push_back(std::stoi(currentLine));
  }
  while (getline(ioIn, currentLine)) {
    MipsSimulator.readInfos.push_back(currentLine);
  }
  MipsSimulator.outFile = outFile;

  MipsScanner.traverse_bin_codes();
  MipsScanner.traverse_asm_codes();

  MipsSimulator.init_regs();
  MipsSimulator.exec_bin_code();

  return 0;
}