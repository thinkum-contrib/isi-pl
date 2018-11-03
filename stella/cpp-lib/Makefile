# Makefile for libcpp-primal.a

# Version: Makefile,v 1.10 1997/11/08 01:12:28 hans Exp

STELLA-ROOT = ./..
VPATH = .:gc

# g++ settings:
CXX   = g++
CC    = gcc
CFLAGS = -w -O2 -g # -pg
CXXFLAGS = $(CFLAGS)

# Centerline settings:
#CXX   = CC
#CC    = cc
#CFLAGS = -g
#CXXFLAGS = -g

# Comment the value of this variable to not use the garbage collector:
GC-CFLAGS = -DSTELLA_USE_GC -I$(STELLA-ROOT)/cpp-lib/gc/include

LIBS  = 

override INCLUDE += \
	-I$(STELLA-ROOT) \
	-I$(STELLA-ROOT)/cpp-lib

PROG  = libcpp-primal.o
LIB  = libcpp-primal.a
GC-LIB = libgc.a
LDFLAGS = -r
PARSER-GENERATOR = bison
PARSER-FLAGS = -dtv -p stella_ 
SCANNER-GENERATOR = flex
SCANNER-FLAGS = 

# C-SRCS should be compiled with a C compiler and loaded with the -C
#   (C mode) option in Centerline 
C-SRCS = alloca.c

# DOTC-SRCS have the .c extension but should be loaded as C++ files
#   in centerline
DOTC-SRCS = stella-parser.tab.c lex.yy.c 

# CPP-SRCS have .cc extension and are loaded as C++ files
CPP-SRCS =  ObjectPtr.Vec.cc ObjectPtr.ObjectPtr.Map.cc \
             ObjectPtr.ObjectPtr.VHMap.cc String.ObjectPtr.Map.cc \
             String.ObjectPtr.VHMap.cc String.int.Map.cc \
     	     String.int.VHMap.cc hashfns.cc cpp-primal.cc

C-OBJS = $(C-SRCS:.c=.o)

CPP-OBJS = $(DOTC-SRCS:.c=.o) $(CPP-SRCS:.cc=.o) 

HEADERS = $(C-SRCS:.c=.h) $(DOTC-SRCS:.c=.h) $(CPP-SRCS:.cc=.h)

#$(PROG): $(C-OBJS) $(CPP-OBJS)
#	$(CXX) $(LDFLAGS) $(C-OBJS) $(CPP-OBJS) -o $(PROG)

$(LIB): $(C-OBJS) $(CPP-OBJS) $(GC-LIB)
	ar r $(LIB) $(C-OBJS) $(CPP-OBJS)
	ranlib $(LIB)

# Build the garbage collector if necessary:
$(GC-LIB):
	if (test -n "$(GC-CFLAGS)") then \
	  cd gc; \
	  $(MAKE) $(MFLAGS) CC=$(CC) gc.a; \
	  $(MAKE) $(MFLAGS) CC=$(CC) CXX=$(CXX) c++; \
	  rm -f $(GC-LIB); ln -s gc.a $(GC-LIB); \
	fi

#
# Objectcenter rules
# 

# Objectcenter load objects
oc-objs: $(C-OBJS) $(CPP-OBJS)
	#load -C $(C-OBJS)
	#load -CXX $(CPP-OBJS)


# Objectcenter load sources
oc-srcs: $(C-SRCS) $(DOTC-SRCS) $(CPP-SRCS)
	#load -C $(C-SRCS)
	#load -CXX $(DOTC-SRCS)
	#load -CXX $(CPP-SRCS)

#
# Parser rules
#

# rule for scanner generator (i.e., flex)
# NOTE: Must postedit lex.yy.c to add initialization code
#       so Centerline doesn't complain.
lex.yy.c: stella-scanner.l
	$(SCANNER-GENERATOR) $(SCANNER-FLAGS) stella-scanner.l
	rm -f tmp-scanner.c
	sed -e '/We put in the/d' -e 's@\* initial match-at-newline will be true.@for (char\* p = b->yy_ch_buf; p < (b->yy_ch_buf \+ b->yy_buf_size \+ 2) ; p\+\+); \*p = 0; /\* added initialization  -erm@p' < lex.yy.c > tmp-scanner.c
	rm -f lex.yy.c
	mv tmp-scanner.c lex.yy.c

lex.yy.o: lex.yy.c
	$(CXX) $(CXXFLAGS) $(GC-CFLAGS) -c $(INCLUDE) lex.yy.c

# rule for parser generator (i.e., bison)
stella-parser.tab.c: stella-parser.y
	$(PARSER-GENERATOR) $(PARSER-FLAGS) stella-parser.y

stella-parser.tab.o: stella-parser.tab.c
	$(CXX) $(CXXFLAGS) $(GC-CFLAGS) -c $(INCLUDE) stella-parser.tab.c

#
# Default rules
# 

#NOTE: we use C++ compiler for files in DOTC-SRCS, e.g. lex.yy.c
#NOTE: we use C compiler for files in C-SRCS, e.g. alloca.c
#      currently this is done by overriding default .c.o inference rule

# default rule for files in DOTC-SRCS
.c.o: $(HEADERS)
	$(CXX) $(CXXFLAGS) $(GC-CFLAGS) -c $(INCLUDE) $<

# rules for files in C-SRCS: overrides default rule for DOTC-SRCS
alloca.o: alloca.c
	$(CC) $(CFLAGS) $(GC-CFLAGS) -c $(INCLUDE) alloca.c

# default rule for files in CPP-SRCS
.cc.o: $(HEADERS)
	$(CXX) $(CXXFLAGS) $(GC-CFLAGS) -c $(INCLUDE) $<

#
# Cleaning up
#

.PHONY: clean extraclean

clean:
	/bin/rm -f $(PROG) $(LIB) *.o *.a core \#*

extraclean: clean
	/bin/rm -f *~ .*~ \#* .\#*
	cd gc; rm -f $(GC-LIB); $(MAKE) $(MFLAGS) clean
