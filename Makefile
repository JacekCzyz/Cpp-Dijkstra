CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++14

__start__: test
	./test

test: obj obj/test.o obj/dij.o obj/matrix.o obj/list.o
	g++ -Wall -pedantic -std=c++0x -o test obj/test.o obj/dij.o obj/matrix.o obj/list.o

obj:
	mkdir obj

obj/test.o: src/test.cpp inc/graf.hpp inc/dij.hpp inc/matrix.hpp inc/list.hpp
	g++ -c ${CXXFLAGS} -o obj/test.o src/test.cpp

obj/list.o: src/list.cpp inc/list.hpp
	g++ -c ${CXXFLAGS} -o obj/list.o src/list.cpp

obj/matrix.o: src/matrix.cpp inc/matrix.hpp
	g++ -c ${CXXFLAGS} -o obj/matrix.o src/matrix.cpp

obj/dij.o: src/dij.cpp inc/dij.hpp
	g++ -c ${CXXFLAGS} -o obj/dij.o src/dij.cpp


clean:
	rm -f obj/*.o test