CXX = g++
CXXFLAGS = -std=c++11

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

all: YourPets1 YourPets2

YourPets1: YourPets1.o
	$(CXX) $(CXXFLAGS) -o YourPets1 YourPets1.o

YourPets2 : YourPets2.o
	$(CXX) $(CXXFLAGS) -o YourPets2 YourPets2.o