# once you add matrix_sub.cc, you need to modify Makefile to include matrix_sub.cc as a dependency
matrix.exe: matrix.cc matrix.h matrix_sub.cc
	g++ -std=c++11 -Wall -Wextra -pedantic -o matrix.exe matrix.cc matrix_sub.cc

clean:
	rm *.exe
