CXXFLAGS_DEBUG=-std=c++11 -g -c -Wall
CXXFLAGS_RELEASE=-std=c++11 -Os -c -Wall
CXXFLAGS=$(CXXFLAGS_DEBUG)

all: lab4

release: CXXFLAGS = $(CXXFLAGS_RELEASE)
release: lab4

lab4: lab4.o
	$(CXX) lab4.o -o lab4

lab4.o: lab4.cc
	$(CXX) $(CXXFLAGS) lab4.cc

clean:
	rm -rf *.o lab4