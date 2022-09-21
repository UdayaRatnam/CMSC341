CXX = g++
CXXFLAGS = -Wall

proj4: hash.o person.o mytest.cpp
	$(CXX) $(CXXFLAGS) person.o hash.o mytest.cpp -o proj4

hash.o: hash.h hash.cpp
	$(CXX) $(CXXFLAGS) -c hash.cpp

person.o: person.h person.cpp
	$(CXX) $(CXXFLAGS) -c person.cpp

clean:
	rm *.o*
	rm *~
