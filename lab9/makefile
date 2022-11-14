test: test.o 
	./test.o
	rm test.o

test.o: test.cpp rbtree.cpp
	g++ -std=c++11 test.cpp rbtree.cpp -o test.o