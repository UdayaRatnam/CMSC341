CXX = g++
CXXFLAGS = -Wall

proj0: puzzle.o mytest.cpp 
	$(CXX) $(CXXFLAGS) puzzle.o mytest.cpp -o proj0

puzzle.o: puzzle.h puzzle.cpp
	$(CXX) $(CXXFLAGS) -c puzzle.cpp


clean:
		rm *.o*
		rm *~ 

run:
	./proj0

