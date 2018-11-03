// main entry point for stella system

#include "stella/stella-system.hh"

using namespace stella;

int main(int count, char** arguments) {
  // Main STELLA entry point.
  { boolean testingP = count == 1;

    std::cout << "Welcome to " << stellaVersionString() << std::endl;
    startup(testingP);
    startupStellaSystem();
    interpretCommandLineArguments(count, arguments);
    if (testingP) {
      std::cout << "Bye!" << std::endl;
    }
  }
  return (1);
}

