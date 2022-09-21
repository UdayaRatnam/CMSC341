CXX = g++
CXXFLAGS = -Wall

lab7: LinkedList.o lab7.cpp
	$(CXX) $(CXXFLAGS) LinkedList.o	lab7.cpp -o lab7

LinkedList.o: LinkedList.h LinkedList.cpp
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

run:
	./lab7

clean:
	-rm -f *~ *.o

val:
	valgrind ./lab7
