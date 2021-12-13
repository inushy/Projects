CXXFLAGS = -pedantic -Wall -Werror -std=c++11

memsim: main.o memory.o hex.o
	g++ $(CXXFLAGS) -o memsim main.o memory.o hex.o
main.o: main.cpp
	g++ $(CXXFLAGS) -c -o main.o main.cpp
memory.o: memory.cpp
	g++ $(CXXFLAGS) -c -o memory.o memory.cpp
hex.o: hex.cpp
	g++ $(CXXFLAGS) -c -o hex.o hex.cpp

clean:
	rm *.o memsim
