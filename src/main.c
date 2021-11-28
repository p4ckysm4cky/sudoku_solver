#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

static void testing()
{
    int board[9][9] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
    display(board);
    printf("Column testing\n");
    int result = inCol(0, 9, board);
    printf("%d\n", result); 
    result = inCol(8, 2, board);
    printf("%d\n", result); 
    result = inCol(3, 5, board);
    printf("%d\n", result); 
    result = inCol(1, 6, board);
    printf("%d\n", result); 
    result = inCol(8, 5, board);
    printf("%d\n", result); 
    result = inCol(3, 4, board);
    printf("%d\n", result); 

    printf("Subgrid testing\n");
    result = inSubgrid(1, 1, 3, board);
    printf("%d\n", result); 
    result = inSubgrid(3, 0, 3, board);
    printf("%d\n", result); 
    result = inSubgrid(1, 1, 6, board);
    printf("%d\n", result); 
    result = inSubgrid(1, 1, 2, board);
    printf("%d\n", result); 
    result = inSubgrid(2, 5, 7, board);
    printf("%d\n", result); 
    result = inSubgrid(8, 8, 1, board);
    printf("%d\n", result); 

    printf("Valid move testing\n");
    result = validMove(2, 0, 1, board);
    printf("%d\n", result); 
    result = validMove(5, 6, 7, board);
    printf("%d\n", result); 
    result = validMove(7, 7, 3, board);
    printf("%d\n", result); 
    result = validMove(4, 2, 5, board);
    printf("%d\n", result); 
    result = validMove(1, 7, 4, board);
    printf("%d\n", result); 
    result = validMove(6, 8, 2, board);
    printf("%d\n", result); 
    printf("Testing solver\n");
    printf("Status: %d\n", solve(board));
    display(board);
}

int main(void)
{
    testing();
}