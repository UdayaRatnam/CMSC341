CXX = g++
CXXFLAGS = -Wall

lab12: Bookshelf.o lab12.cpp
	$(CXX) $(CXXFLAGS) Bookshelf.o lab12.cpp -o lab12

Bookshelf.o: Bookshelf.cpp Bookshelf.h
	$(CXX) $(CXXFLAGS) -c Bookshelf.cpp

clean:
	rm *.o
	rm *~

run:
	./lab12
