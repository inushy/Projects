CXXFLAGS = -pedantic -Wall -Werror -std=c++14

rv32i: main.o rv32i_decode.o memory.o hex.o
	g++ $(CXXFLAGS) -o rv32i main.o rv32i_decode.o memory.o hex.o
main.o: main.cpp
	g++ $(CXXFLAGS) -c -o main.o main.cpp
rv32i_decode.o: rv32i_decode.cpp
	g++ $(CXXFLAGS) -c -o rv32i_decode.o rv32i_decode.cpp
memory.o: memory.cpp
	g++ $(CXXFLAGS) -c -o memory.o memory.cpp
hex.o: hex.cpp
	g++ $(CXXFLAGS) -c -o hex.o hex.cpp

clean:
	rm *.o rv32i
