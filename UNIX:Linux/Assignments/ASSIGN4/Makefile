CXX = g++ 
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

dog: dog.o functions.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

dog.o: dog.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

functions.o: functions.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm *.o dog
