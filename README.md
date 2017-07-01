# Sudoku

CS 111
Spring 2017
Project 2
Sudoku

Introduction Sudoku is a puzzle where you fill in numbers 1–9 on a 9×9 board such that no number is
duplicated in any row, column, or 3×3 sub-grid. For more information about the puzzle, see Wikipedia:
http://en.wikipedia.org/wiki/Sudoku. 

Get started as usual, creating an empty directory for this project.

mkdir -p 111/proj2
At each session, enter the cs111 environment and switch to your directory.
cs111
cd 111/proj2

What to do Write a program to solve a Sudoku puzzle. The input will consist of 9 lines of 9 characters each.
Each character is a numeral (1–9) or an underscore, representing a blank square. The output must similarly
consist of 9 lines of 9 characters each. Each character must be a numeral (1–9), and the whole output must
be a solution to the input puzzle.

Hints This problem will require backtracking that will be facilitated by a stack. Implement an dynamic stack
with the following interface:

class Stack : public cs111Object {
public:
typedef int ItemTy; // Adds ItemTy as another name for int
Stack();
void push(const ItemTy& item);
void pop();
ItemTy top() const;
bool empty() const;
void show() const;
private:
};

You should be able to complete the code for this in short order. Then, devise a SudokuBoard class to support
manipulations like:

void place(r, c, n) // place numeral n at position (r,c)
void print() // write the board to cout
int get(r, c) // return the numeral at position (r,c)
void remove(r, c) // remove the numeral at position (r,c)
bool canPlace(r, c, n)// true iff the board would allow placing n at (r,c)
bool solved() // true iff there are no blank spots on the board

and any others you deem appropriate. The simplest underlying implementation for storage would be an array
of 9 strings, one for each row.

Implement and test your board with throw-away programs until you’re sure it’s correct. At the same time,
be thinking about the design and implementation of the main program.

The basic algorithm uses a stack. The following is a sketch of the ideas. It is up to you to flesh this out into
an algorithm, and implement that algorithm.

Repeatedly, determine the most constrained square on the board—the one that will accept the fewest numerals,
if there is one. Place the smallest acceptable numeral on the square. Push its position r and c onto
the stack. But if there isn’t any square, backtrack by popping c and r, and continuing with the next acceptable
numeral. Stop when the board is solved.

How to Submit When you submit your work, the submission system will collect these files:

• Stack.h
• Stack.cc
• SudokuBoard.h
• SudokuBoard.cc
• sudoku.cc
