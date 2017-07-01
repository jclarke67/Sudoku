output: sudoku.o Stack.o Board.o 
	g++ sudoku.o Stack.o Board.o -o output

sudoku.o: sudoku.cc Board.h Stack.h 
	g++ -c sudoku.cc
	
Stack.o: Stack.cc Stack.h
	g++ -c Stack.cc
	
Board.o: Board.cc Board.h Stack.h
	g++ -c Board.cc

clean:
	rm *.o