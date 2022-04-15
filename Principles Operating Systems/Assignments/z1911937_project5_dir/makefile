#
#  PROGRAM:   Assignment 5
#  AUTHOR:    Anushka Verma
#  LOGON ID:  Z1911937
#  DUE DATE:  04/16/2022
#
CCFLAGS = -Wall -g
all: z1911937_project5 z1911937_project5_p2

z1911937_project5: z1911937_project5.o
	g++ $(CCFLAGS) -o z1911937_project5 z1911937_project5.o -lpthread

z1911937_project5.o: z1911937_project5.cc
	g++ $(CCFLAGS) -c z1911937_project5.cc -lpthread

z1911937_project5_p2: z1911937_project5_p2.o
	g++ $(CCFLAGS) -o z1911937_project5_p2 z1911937_project5_p2.o -lpthread

z1911937_project5_p2.o: z1911937_project5_p2.cc
	g++ $(CCFLAGS) -c z1911937_project5_p2.cc -lpthread

clean:
	rm *.o z1911937_project5 z1911937_project5_p2