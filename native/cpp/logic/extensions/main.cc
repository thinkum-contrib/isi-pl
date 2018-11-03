// main entry point for powerloom-extensions system

#include "logic/extensions/powerloom-extensions-system.hh"

using namespace stella_utilities;
using namespace pli;
using namespace logic;
using namespace stella;
using namespace stella_plx;

int main() {
  // Main PowerLoom entry point for your code in C++ and Java.
  std::cout << "Initializing STELLA..." << std::endl;
  startupStellaSystem();
  std::cout << "Initializing PowerLoom..." << std::endl;
  startupLogicSystem();
  std::cout << "Initializing PowerLoom extensions..." << std::endl;
  startupPowerloomExtensionsSystem();
  stella::stringChangeModule("PL-USER");
  powerloom();
  return (1);
}

