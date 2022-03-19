#include <iostream>
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
  bool data_start = false;
  bool data_end = false;
  for (int i=0;i<asmCodes.size();i++) {
    std::vector<std::string> asmVec = spilt_asm_code(asmCodes[i]);
    for (int j=0;j<asmVec.size();j++) {
      std::cout << asmVec[j] << std::endl;
    }
  }
}

std::vector<std::string> Scanner::spilt_asm_code(std::string currentLine) {
  std::vector<std::string> tokens;
  std::string token = "";
  bool typeStart = false;
  bool typeEnd = false;
  bool dataStart = false;
  for (int i=0;i<currentLine.size();i++) {
    if (annotation_start(currentLine[i])) {
      tokens.push_back(token);
      break;
    } // meet #, break
    if (!typeStart) {
      if (currentLine[i] == '.') 
        typeStart = true; 
      else continue;
    } // meet ., start to read datatype
    if (typeStart && !typeEnd) {
      if (is_token_empty(currentLine[i])) {
        typeEnd = true;
        tokens.push_back(token);
        token = "";
      }
      else {
        if (i == currentLine.size()-1) {
          token = token + currentLine[i];
          tokens.push_back(token);
          continue;
        }
        else {
          token = token + currentLine[i];
          continue;
        }
      }
    } // if datatype finished, put token to tokens and init token
    if (typeEnd && !dataStart) {
      if (is_token_empty(currentLine[i])) continue;
      else {
        if (tokens[0]==".word" || tokens[0]==".half" || tokens[0]==".byte") {
          dataStart = true;
          token = token + currentLine[i];
        }
        else {
          dataStart = true;
        }
        continue;
      }
    } // when tokens[0] got, read until useful
    if (dataStart) {
      if (tokens[0]==".word" || tokens[0]==".half" || tokens[0]==".byte") {
        if (i == currentLine.size()-1) {
          if (is_token_empty(currentLine[i])) {
            tokens.push_back(token);
            break;
          }
          else {
            token = token + currentLine[i];
            tokens.push_back(token);
            break;
          }
        }
        else {
          if (is_token_empty(currentLine[i])) continue;
          else {
            token = token + currentLine[i];
          }
        }
      }
      else {
        if (currentLine[i] == '\"') {
          tokens.push_back(token);
          break;
        }
        else {
          token = token + currentLine[i];
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