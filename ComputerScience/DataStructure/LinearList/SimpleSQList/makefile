test : SeqList.o
	g++ SeqList.o -o test 
SeqList.o : SeqList.cpp  SeqListheader.hpp 
	g++ -c -Wall -g SeqList.cpp

.PHONY : clean

clean :
	rm SeqList.o test
