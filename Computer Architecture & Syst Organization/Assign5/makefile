CXXFLAGS = -pedantic -Wall -Werror -std=c++14

rv32i: main.o rv32i_decode.o rv32i_hart.o registerfile.o cpu_single_hart.o memory.o hex.o
	g++ $(CXXFLAGS) -o rv32i main.o rv32i_decode.o rv32i_hart.o registerfile.o cpu_single_hart.o memory.o hex.o
main.o: main.cpp
	g++ $(CXXFLAGS) -c -o main.o main.cpp
rv32i_decode.o: rv32i_decode.cpp
	g++ $(CXXFLAGS) -c -o rv32i_decode.o rv32i_decode.cpp
registerfile.o: registerfile.cpp
	g++ $(CXXFLAGS) -c -o registerfile.o registerfile.cpp
cpu_single_hart.o: cpu_single_hart.cpp
	g++ $(CXXFLAGS) -c -o cpu_single_hart.o cpu_single_hart.cpp
rv32i_hart.o: rv32i_hart.cpp
	g++ $(CXXFLAGS) -c -o rv32i_hart.o rv32i_hart.cpp
memory.o: memory.cpp
	g++ $(CXXFLAGS) -c -o memory.o memory.cpp
hex.o: hex.cpp
	g++ $(CXXFLAGS) -c -o hex.o hex.cpp

clean:
	rm *.o rv32i
