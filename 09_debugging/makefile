
CXXFLAGS = -O3 -ggdb -m64
LDFLAGS  = -m64

all: hello.exe
.PRECIOUS: hello.exe hello.o
.PHONY: all clean

%.o: %.cc
    $(CXX) -c $< -o $@ $(CXXFLAGS)

%.exe: %.o
    $(CXX) $^ -o $@ $(LDFLAGS)

clean:
    rm -f hello.o hello.exe