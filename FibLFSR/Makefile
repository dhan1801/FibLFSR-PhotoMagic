CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Werror

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework

all: PhotoMagic test PhotoMagic.a

PhotoMagic: main.o FibLFSR.o PhotoMagic.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: test.o FibLFSR.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

PhotoMagic.a: FibLFSR.o PhotoMagic.o
	ar rcs $@ $^

%.o: %.cpp FibLFSR.hpp PhotoMagic.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o PhotoMagic test PhotoMagic.a

.PHONY: all clean