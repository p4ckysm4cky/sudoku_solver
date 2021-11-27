#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"


/* Prints out the sudoku board*/
void display(int board[][9])
{
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            printf("%d ", board[y][x]);
        }
        putchar('\n');
    }
}


