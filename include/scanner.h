#ifndef SCANNER_H
#define SCANNER_H
#include <vector>
#include <string>
#include <map>
#include "mem_and_reg.h"

class Scanner {
 public:
  std::vector<std::string> asmCodes;
  std::vector<std::string> binCodes;

  void traverse_asm_codes();
  void traverse_bin_codes();

 private:
  void write_bin_to_mem(std::string binCode);
  int binstr_to_int(std::string binStr);

  std::vector<std::string> spilt_asm_code(std::string currentLine);
  bool is_token_empty(char currentChar);
  bool is_token_end(char currentChar);
  bool annotation_start(char currentChar);
  void write_data_to_mem(std::vector<std::string> tokens);
};

#endif
