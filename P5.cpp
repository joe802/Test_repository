////
// NAME: Joseph Park
// SECTION: 2848
// PROGRAM NAME: P5
//
//
// test text
// DESCRIPTION:
// This file will solve the Knight's Journey problem using a recursive function approach.  
// It will solve for any size 2D array using a brute force approach and will output the
// final array solution, number of tries, and number of bad tries.
///

#include <iomanip>
#include <iostream>

using namespace std;

const int boardDimRow = 8;								//How many rows the board has
const int boardDimCol = 8;								//How many cols the board has

int moveCount(0), tries(0), badTries(0);				//Initialize global moves and tries counts
int board[boardDimRow][boardDimCol];					//initialize the board as a global variable

bool moveKnight(int row, int col, int movNum);			
//Function will recursively move the knight through every possible combination
//PRECOND: provide a row, col to move by and the current move number
//POSTCOND: will return a true if a solution was successfully found, false if not

void printBoard(const int board[][boardDimCol], int rowDim); 
//Will print argument 2D board array and its contents
//PRECOND: provide 2x2 array and row Dim
//POSTCOND: will print to screen the array

void resetArray(int board[][boardDimCol], int rowDim);  
//Will reset argument 2D array contents to all zeros
//PRECOND: provide 2x2 array and row dim
//POSTCOND: will replace all values of the array with zeros

int main() {
	int rowStart(0), colStart(0), moveStart(1);			//Initialize board start position

	resetArray(board, boardDimRow);						//Set board values to zeros
	moveKnight(rowStart, colStart, moveStart);			//Initial function call

	cout << "It worked! Total tries: " << tries << endl;
	cout << "Total bad tries: " << badTries << endl;
	cout << "The final board is: \n\n";					//Print out results and statistics
	printBoard(board, boardDimRow);
	return 0;
}

bool moveKnight(int row, int col, int movNum) {
	//Check if within board boundaries, return false if not within board
	if (row > (boardDimRow-1) || row < 0 || col > (boardDimCol - 1) || col < 0) {return false; }
	
	//Check if the current row/col is empty, return false if not empty
	else if (board[row][col] != 0) { return false;}		
	
	//Check if you have reached the last move, return true and end recursion
	else if (movNum == (boardDimRow * boardDimCol)) {	
		tries++;
		board[row][col] = movNum;
		return true;
	}
	//Try next move
	else {
		tries++;										//increment tries	
		board[row][col] = movNum;						//insert current move onto board

		if (moveKnight(row - 2, col + 1, movNum + 1) == true) { return true; }//Move #1, if false, next move#
		if (moveKnight(row - 1, col + 2, movNum + 1) == true) { return true; }//Move #2
		if (moveKnight(row + 1, col + 2, movNum + 1) == true) { return true; }//Move #3
		if (moveKnight(row + 2, col + 1, movNum + 1) == true) { return true; }//Move #4
		if (moveKnight(row + 2, col - 1, movNum + 1) == true) { return true; }//Move #5
		if (moveKnight(row + 1, col - 2, movNum + 1) == true) { return true; }//Move #6
		if (moveKnight(row - 1, col - 2, movNum + 1) == true) { return true; }//Move #7
		if (moveKnight(row - 2, col - 1, movNum + 1) == true) { return true; }//Move #8
		
		badTries++;										//If all 8 moves did not work, increment badTries
		board[row][col] = 0;							//Undo movNum insertion from above
		return false;									//Return false to step back up recursion tree
	}
}

void printBoard(const int board[][boardDimCol], int rowDim) {
	//Loop through row col and print each element
	for (int i = 0; i < rowDim; i++) {
		for (int j = 0; j < boardDimCol; j++) {
			cout << board[i][j] << "\t";
			if (j == boardDimCol-1) { cout << endl; }
		}
	}
	cout << endl;
}

void resetArray(int board[][boardDimCol], int rowDim) {
	//loop through row col and reset each element to 0
	for (int i = 0; i < rowDim; i++) {
		for (int j = 0; j < boardDimCol; j++) {
			board[i][j] = 0;
			if (j == boardDimCol-1) { cout << endl; }
		}
	}
}

/*
It worked! Total tries: 3242065
Total bad tries: 3242001
The final board is:

1       38      55      34      3       36      19      22
54      47      2       37      20      23      4       17
39      56      33      46      35      18      21      10
48      53      40      57      24      11      16      5
59      32      45      52      41      26      9       12
44      49      58      25      62      15      6       27
31      60      51      42      29      8       13      64
50      43      30      61      14      63      28      7


C:\Users\josep\source\repos\P5\Debug\P5.exe (process 28068) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/
