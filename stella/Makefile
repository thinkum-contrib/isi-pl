# Makefile for Stella

# Version: Makefile,v 1.9 1997/11/09 02:28:58 hans Exp

STELLA-ROOT = .
VPATH = .:cpp-lib

# g++ settings:
CXX    = g++
CC     = gcc
CFLAGS = -w -g # -pg -O2

# Centerline settings:
#CXX    = CC
#CC     = cc
#CFLAGS = -g

# Comment the values of these variables to not use the garbage collector:
GC-CFLAGS = -DSTELLA_USE_GC -I$(STELLA-ROOT)/cpp-lib/gc/include
GC-LDFLAGS = -Lcpp-lib/gc
GC-LIB = -lgc

override INCLUDE += \
	-I$(STELLA-ROOT) \
	-I$(STELLA-ROOT)/cpp-lib

LDFLAGS = -Lcpp-lib # -pg
LIBS = -lcpp-primal -lm

PROG  = stella
LIB = libstella.a
LIB-PRIMAL = libcpp-primal.a

LIB-SRCS =   hierarchy.cc \
	     taxonomies.cc \
	     streams.cc \
	     primal.cc \
	     type-predicates.cc \
             conses.cc \
	     lists.cc \
	     collections.cc \
             iterators.cc \
	     symbols.cc \
	     boot-symbols.cc \
	     literals.cc \
      	     classes.cc \
	     methods.cc \
	     defclass.cc \
             stella-in.cc \
	     foreach.cc \
	     walk.cc \
             dynamic-slots.cc \
	     dynamic-literal-slots.cc \
	     cl-translate.cc \
	     macros.cc \
	     describe.cc \
	     demons.cc \
             more-demons.cc \
             modules.cc \
	     contexts.cc \
	     read.cc \
             translate-file.cc \
   	     cl-translate-file.cc \
	     cpp-translate.cc \
             cpp-translate-file.cc \
             cpp-class-out.cc \
	     cpp-output.cc \
	     java-translate.cc \
             java-translate-file.cc \
             java-class-out.cc \
	     java-output.cc \
	     idl-translate.cc \
             idl-translate-file.cc \
             idl-class-out.cc \
	     idl-output.cc \
	     your-file.cc \
	     your-file2.cc \
	     startup.cc

LIB-OBJS = $(LIB-SRCS:.cc=.o) 

CPP-SRCS = $(LIB-SRCS) main.cc
CPP-OBJS = $(CPP-SRCS:.cc=.o) 

HEADERS =  $(CPP-SRCS:.cc=.hh)


$(PROG): $(CPP-OBJS) $(LIB-PRIMAL)
	$(CXX) $(LDFLAGS) $(GC-LDFLAGS) $(CPP-OBJS) $(CPP-LIB) \
	       -o $(PROG) $(LIBS) $(GC-LIB)

$(LIB): $(LIB-OBJS)
	ar r $(LIB) $(LIB-OBJS)
	ranlib $(LIB)

$(LIB-PRIMAL):
	cd cpp-lib; $(MAKE) $(MFLAGS) CC=$(CC) CXX=$(CXX)

#
# Objectcenter rules
# 

# Objectcenter load objects
oc-objs: $(CPP-OBJS)
	#load -CXX $(CPP-OBJS)
	#cd cpp-lib
	#make oc-objs
	#cd ..

# Objectcenter load sources
oc-srcs: $(CPP-SRCS)
	#load -CXX $(CPP-SRCS)

#
# Default rules
# 

.cc.o: $(HEADERS)
	$(CXX) $(CFLAGS) $(GC-CFLAGS) -c $(INCLUDE) $<

#
# Cleaning up
#

.PHONY: clean extraclean

clean:
	/bin/rm -f $(LIB) *.o core \#*
	cd cpp-lib; $(MAKE) $(MFLAGS) clean

extraclean: clean
	/bin/rm -f $(PROG) *~ .*~ \#* .\#*
	cd cpp-lib; $(MAKE) $(MFLAGS) extraclean
