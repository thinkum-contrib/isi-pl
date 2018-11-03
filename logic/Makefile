# Makefile for PowerLoom

# Version: Makefile,v 1.5 1997/09/23 04:45:20 hans Exp

LOGIC-ROOT = $(PWD)
STELLA-ROOT = $(LOGIC-ROOT)/../stella
BIN = $(LOGIC-ROOT)/../bin
VPATH = $(LOGIC-ROOT):$(STELLA-ROOT):$(STELLA-ROOT)/cpp-lib

# g++ settings:
CXX    = g++
CC     = gcc
CFLAGS = -w -g # -pg -O2

# Centerline/Sparcworks settings:
#CXX    = CC
#CC     = cc
#CFLAGS = -g

override INCLUDE += \
	-I$(LOGIC-ROOT) \
	-I$(STELLA-ROOT) \
	-I$(STELLA-ROOT)/cpp-lib

# Comment the values of these three variables to not use the garbage collector:
GC-CFLAGS = -DSTELLA_USE_GC -I$(STELLA-ROOT)/cpp-lib/gc/include
GC-LDFLAGS = -L$(STELLA-ROOT)/cpp-lib/gc
GC-LIB = -lgc

OTHER-CFLAGS = -DDEMO_FILE_PATHNAME=\"$(LOGIC-ROOT)/demos/\"

LDFLAGS = -L$(STELLA-ROOT) -L$(STELLA-ROOT)/cpp-lib # -pg
LIBS = -lstella -lcpp-primal -lm

PROG  = $(BIN)/powerloom
LIB = libpowerloom.a
LIB-STELLA = libstella.a
LIB-PRIMAL = libcpp-primal.a

all: $(PROG)

LIB-SRCS =  logic-macros.cc \
	    kif-in.cc \
	    propositions.cc \
	    caches.cc \
	    descriptions.cc \
	    rules.cc \
	    partial-match.cc \
	    query.cc \
	    kif-out.cc \
	    print.cc \
	    specialize.cc \
	    optimize.cc \
	    normalize.cc \
	    logic-in.cc \
	    api-support.cc \
            gfp.cc \
	    api.cc

LIB-OBJS = $(LIB-SRCS:.cc=.o) 

CPP-SRCS = $(LIB-SRCS) powerloom.cc
CPP-OBJS = $(CPP-SRCS:.cc=.o) 

HEADERS =  $(CPP-SRCS:.cc=.hh)


$(PROG): $(CPP-OBJS) $(LIB-STELLA) $(LIB-PRIMAL)
	$(CXX) $(LDFLAGS) $(GC-LDFLAGS) $(CPP-OBJS) $(CPP-LIB) \
	       -o $(PROG) $(LIBS) $(GC-LIB)

$(LIB): $(LIB-OBJS)
	ar r $(LIB) $(LIB-OBJS)
	ranlib $(LIB)

$(LIB-STELLA):
	cd $(STELLA-ROOT); \
	$(MAKE) $(MFLAGS) CC=$(CC) CXX=$(CXX) INCLUDE="-I- -I$(LOGIC-ROOT)" \
		$(LIB-STELLA)

$(LIB-PRIMAL):
	cd $(STELLA-ROOT)/cpp-lib; \
	$(MAKE) $(MFLAGS) CC=$(CC) CXX=$(CXX) INCLUDE="-I- -I$(LOGIC-ROOT)" \
		$(LIB-PRIMAL)

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
	$(CXX) $(CFLAGS) $(GC-CFLAGS) $(OTHER-CFLAGS) -c $(INCLUDE) $<

#
# Manual
#

.PHONY: manual

manual:
	cd doc; $(MAKE) $(MFLAGS) all

#
# Cleaning up
#

.PHONY: clean extraclean

clean:
	/bin/rm -f $(LIB) *.o core \#*
	cd $(STELLA-ROOT); $(MAKE) $(MFLAGS) clean
	cd doc; $(MAKE) $(MFLAGS) clean

extraclean: clean
	/bin/rm -f $(PROG) *~ .*~ \#* .\#*
	cd $(STELLA-ROOT); $(MAKE) $(MFLAGS) extraclean
	cd doc; $(MAKE) $(MFLAGS) extraclean
