#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"


/* Prints out the sudoku board */
void display(int board[][9])
{
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++)
            printf("%d ", board[y][x]);
        putchar('\n');
    }
}


/* returns true if number is in specified row */
int inRow(int y, int number, int board[][9])
{
    for (int x = 0; x < 9; x++) {
        if (board[y][x] == number) 
            return 1;    
    }
    return 0;
}


/* return true if number is in specified column */
int inCol(int x, int number, int board[][9])
{
    for (int y = 0; y < 9; y++) {
        if (board[y][x] == number)
            return 1;
    }
    return 0;
}


/*  return true if number is already in subgrid */
int inSubgrid(int x, int y, int number, int board[][9])
{
    // Finding subgrid startion position
    int start_x = x - (x % 3);
    int start_y = x - (y % 3);
    // Searching
    for (int y = start_y; y < start_y+3; y++) {
        for (int x = start_x; x < start_x+3; x++) {
            if (board[y][x] == number)
                return 1;
        }
    }
    return 0;
}