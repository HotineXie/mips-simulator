#include <vector>
#include <fstream>
#include <string>
#include <map>

class Scanner {
 public:
  std::vector<std::string> asmCodes;
  std::vector<std::string> binCodes;

  void traverse_asm_codes();
  void traverse_bin_codes();

 private:
  void write_bin_to_mem(std::string binCode);
  int binstr_to_int(std::string binStr);

  std::vector<std::string> spilt_asm_code(std::string);
  bool is_token_empty(char currentChar);
  bool is_token_end(char currentChar);
  bool annotation_start(char currentChar);
};
