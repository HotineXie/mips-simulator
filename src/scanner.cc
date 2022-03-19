#include <iostream>
#include "scanner.h"

extern void *mem_ptr;
extern void *text_ptr;
extern void *static_data_ptr;

void Scanner::traverse_bin_codes() {
  for (int i=0;i<binCodes.size();i++) {
    write_bin_to_mem(binCodes[i]);
  }
}

void Scanner::write_bin_to_mem(std::string binCode) {
  *(int *)text_ptr = binstr_to_int(binCode);
  text_ptr = (int *)text_ptr + 1;
}

int Scanner::binstr_to_int(std::string binStr) {
  int result = 0;
  for (int i=0;i<binStr.size();i++) {
    int tmp = (binStr[binStr.size()-1-i]-'0');
    std::cout << tmp;
    tmp = tmp << i;
    result += tmp;
  }
  std::cout << std::endl;
  return result;
}
