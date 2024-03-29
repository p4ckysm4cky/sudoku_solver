#ifndef SUDOKU_H
#define SUDOKU_H

void display(int board[][9]);
int inRow(int y, int number, int board[][9]);
int inCol(int x, int number, int board[][9]);
int inSubgrid(int x, int y, int number, int board[][9]);
int validMove(int x, int y, int number, int board[][9]);
int solve(int board[][9]);

#endif