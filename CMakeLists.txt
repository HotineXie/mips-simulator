cmake_minimum_required (VERSION 3.16)
project (mips-simulator)

include_directories(include)
add_executable(mips-simulator src/main.cc src/scanner.cc src/dump.cc src/simulator.cc)
