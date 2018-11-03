// Garbage collector definitions

// Version: gc.hh,v 1.1 1997/04/15 01:51:46 hans Exp

// To use the Boehm garbage collector with the C++ version of Stella
// supply the flag '-DSTELLA_USE_GC' to the C/C++ compiler.

#ifdef STELLA_USE_GC
#  include "gc_cpp.h"
#else
#  include "gc_cpp_dummy.h"
#endif
