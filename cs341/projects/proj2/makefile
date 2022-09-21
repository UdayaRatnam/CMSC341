CXX = g++
CXXFLAGS = -Wall

proj2: dtree.o utree.o mytest.cpp
	$(CXX) $(CXXFLAGS) dtree.o utree.o mytest.cpp -o proj2

dtree.o: dtree.h dtree.cpp
	$(CXX) $(CXXFLAGS) -c dtree.cpp

utree.o: utree.h utree.cpp
	$(CXX) $(CXXFLAGS) -c utree.cpp

clean:
	rm *.o*
	rm *~