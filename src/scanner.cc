#include <iostream>
#include <regex>
#include "scanner.h"

extern void *mem_ptr;
extern void *text_ptr;
extern void *static_data_ptr;

void Scanner::traverse_bin_codes() {
  for (int i=0;i<binCodes.size();i++) {
    write_bin_to_mem(binCodes[i]);
  }
  text_ptr = mem_ptr;  // reset text_ptr addr
}

void Scanner::write_bin_to_mem(std::string binCode) {
  *(int *)text_ptr = binstr_to_int(binCode);
  text_ptr = (int *)text_ptr + 1;
}

int Scanner::binstr_to_int(std::string binStr) {
  int result = 0;
  for (int i=0;i<binStr.size();i++) {
    int tmp = (binStr[binStr.size()-1-i]-'0');
    tmp = tmp << i;
    result += tmp;
  }
  return result;
}

void Scanner::traverse_asm_codes() {
  bool dataStart = false;
  bool dataEnd = false;
  std::vector<std::string> tokens;
  for (int i=0;i<asmCodes.size();i++) {
    tokens = spilt_asm_code(asmCodes[i]);

    if (tokens.empty()) continue;
    if (tokens[0] == ".text") break;
    if (dataStart) {
      write_data_to_mem(tokens);
    }
    if (tokens[0] == ".data") {
      dataStart = true;
      continue;
    for (int j=0;j<tokens.size();j++) {
      std::cout << tokens[j] << std::endl;
    }
    }
  }
}

std::vector<std::string> Scanner::spilt_asm_code(std::string currentLine) {
  std::vector<std::string> tokens;
  for (int i=0;i<currentLine.size();i++) {
    if (currentLine[i] == '#') {
      currentLine.erase(i);
      break;
    }
  }
  for (int i=0;i<currentLine.size();i++) {
    if (currentLine[i] == '.') {
      currentLine.erase(0,i);
      break;
    }
  }
  if (!currentLine.empty()) {
    currentLine.erase(0,currentLine.find_first_not_of("\t"));
    currentLine.erase(0,currentLine.find_first_not_of(" "));
    currentLine.erase(currentLine.find_last_not_of(" ")+1);
    currentLine.erase(currentLine.find_last_not_of("\t")+1);
  }

  std::string::size_type pos = 0;
  while ((pos=currentLine.find("\\n")) != std::string::npos) {
    currentLine.replace(pos, 2, "\n");
  }

  std::string token = "";
  bool readType = true;
  bool readData = false;
  for (int i=0;i<currentLine.size();i++) {
    if (readType) {
      if (i == currentLine.size()-1) {
        token = token + currentLine[i];
        tokens.push_back(token);
        break;
      }
      if (is_token_empty(currentLine[i])) {
        tokens.push_back(token);
        token = "";
        readType = false;
      }
      else token = token + currentLine[i];
    }
    else {
      if (!readData) {
        if (is_token_empty(currentLine[i])) continue;
        else if (tokens[0] == ".word" || tokens[0] == ".byte" || tokens[0] == ".half") {
          readData = true;
          token = token + currentLine[i];
        }
        else readData = true;
      }
      else {
        if (tokens[0] == ".word" || tokens[0] == ".byte" || tokens[0] == ".half") {
          if (i == currentLine.size()-1) {
            token = token + currentLine[i];
            tokens.push_back(token);
          }
          if (!is_token_empty(currentLine[i])) token = token + currentLine[i]; 
        }
        else {
          if (currentLine[i] == '\"') {
            tokens.push_back(token);
          }
          else token = token + currentLine[i];
        }
      }
    }
  }
  return tokens;
}

bool Scanner::is_token_empty(char currentChar) {
  if (currentChar == ' ' || currentChar == '\t') {
    return true;
  }
  return false;
}

bool Scanner::annotation_start(char currentChar) {
  if (currentChar == '#') {
    return true;
  }
  return false;
}

void Scanner::write_data_to_mem(std::vector<std::string> tokens) {
  for (int i=0;i<tokens.size();i++) {
    std::cout << tokens[i] << " ";
  }
  std::cout << std::endl;
}