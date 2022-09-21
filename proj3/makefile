CXX = g++
CXXFLAGS = -Wall


proj3: rqueue.o mytest.cpp
	$(CXX) $(CXXFLAGS) rqueue.o mytest.cpp -o proj3

rqueue.o: rqueue.cpp rqueue.h
	$(CXX) $(CXXFLAGS) -c rqueue.cpp

clean:
	rm *.o*
	rm *~