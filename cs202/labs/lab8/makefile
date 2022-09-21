CXX = g++
CXXFLAGS = -Wall -g

lab8: lab8.cpp
	$(CXX) $(CXXFLAGS) lab8.cpp -o lab8

run:
	./lab8

val:
	valgrind ./lab8

clean:
	rm *.o
	rm *~

vg:
	rm vgcore*
