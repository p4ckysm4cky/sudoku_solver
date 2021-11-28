#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"


/* Prints out the sudoku board */
void display(int board[][9])
{
    for (int y = 0; y < 9; y++) {
        if (y % 3 == 0)
            printf("+-----+-----+-----+\n");
        for (int x = 0; x < 9; x++)
            if (x % 3 == 0)
                printf("|%d ", board[y][x]);
            else if (x == 8)
                printf("%d|", board[y][x]);
            else if (x % 3 == 2)
                printf("%d", board[y][x]);
            else
                printf("%d ", board[y][x]);
        putchar('\n');
    }
    printf("+-----+-----+-----+\n");
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
    int start_y = y - (y % 3);
    // Searching
    for (int y = start_y; y < start_y+3; y++) {
        for (int x = start_x; x < start_x+3; x++) {
            if (board[y][x] == number)
                return 1;
        }
    }
    return 0;
}


/* return true if we can place number at position */
int validMove(int x, int y, int number, int board[][9])
{
    char checkRow = ! (char) inRow(y, number, board);
    char checkCol = ! (char) inCol(x, number, board);
    char checkSub = ! (char) inSubgrid(x, y, number, board);
    return (checkRow && checkCol && checkSub);

}


/* Solve sudoku board recursively */
int solve(int board[][9])
{
    // Find the nearest empty cell
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (board[y][x] == 0) {
                // Slot in first valid number
                for (int num = 1; num < 10; num++) {
                    if (validMove(x, y, num, board)) {
                        board[y][x] = num;
                        // We return true if the final solve call is true
                        if ((solve(board)))
                            return 1;
                    }
                }
                // return false if no valid for cell
                board[y][x] = 0;
                return 0;
            }
        }
    }
    // return true if there are no empty cells
    return 1;
}