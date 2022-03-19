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
  void write_bin_to_mem(std::string binCode);
  int binstr_to_int(std::string binStr);

 private:
};
