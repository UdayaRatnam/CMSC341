CXX = g++
CXXFLAGS = -Wall

lab9: Candle.o Scented.o Birthday.o lab9.cpp
	$(CXX) $(CXXFLAGS) Candle.o Scented.o Birthday.o lab9.cpp -o lab9

Birthday.o: Birthday.cpp Birthday.h
	$(CXX) $(CXXFLAGS) -c Birthday.cpp

Scented.o: Scented.cpp Scented.h
	$(CXX) $(CXXFLAGS) -c Scented.cpp

Candle.o: Candle.cpp Candle.h
	$(CXX) $(CXXFLAGS) -c Candle.cpp

clean:
	rm *.o
	rm *~

run:
	./lab9
