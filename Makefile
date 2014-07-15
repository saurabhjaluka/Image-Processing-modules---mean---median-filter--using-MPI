## 

SRCS = serial.cc parallel.cc image.cc image_utils.cc file_utils.cc
OBJS = $(SRCS:.cc=.o)

## OPT_FLAG = -O2
OPT_FLAG = -g

CXX_FLAGS=$(OPT_FLAG)
LD_FLAGS=-ltiff -lz

CC = mpicc
CXX = mpicxx

.SUFFIXES: .cc .o
.cc.o:
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

default: pfilter
all: demo pfilter

help:
	@echo "make all       => compile everything"
	@echo "make demo      => compile image processing demo"
	@echo "make pfilter   => compile pfilter application"
	@echo "make clean     => clean compiled objs and executables"
	@echo "make squeaky   => deep clean everything"

demo: demo.o $(OBJS)
	$(CXX) -o $@ $^ $(LD_FLAGS) -lm

pfilter: pfilter.o $(OBJS)
	$(CXX) -o $@ $^ $(LD_FLAGS) -lm

clean:
	/bin/rm -f *.o demo pfilter
	/bin/rm -f *.tiff

squeaky: clean
	/bin/rm -f *~
