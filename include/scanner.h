#include <vector>
#include <fstream>
#include <string>
#include <map>

// struct Memory {
//   void *mem_ptr = (void *)malloc(0x600000);
//   void *static_data_ptr = (void *)((int *)mem_ptr + 0x100000);
// };

// Memory Mem;

class Scanner {
 public:
  void read_asm_code();
  void read_bin_code();

 private:

};
