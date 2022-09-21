CXX = g++
CXXFLAGS = -Wall

proj1: buffer.o bufferlist.o mytest.cpp
	$(CXX) $(CXXFLAGS) buffer.o bufferlist.o mytest.cpp -o proj1

buffer.o: buffer.h buffer.cpp
	$(CXX) $(CXXFLAGS) -c buffer.cpp

bufferlist.o : bufferlist.h bufferlist.cpp
	$(CXX) $(CXXFLAGS) -c bufferlist.cpp

clean:
	rm *.o*
	rm *~