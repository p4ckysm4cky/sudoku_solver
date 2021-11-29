#include <stdio.h>
#include "retrieve.h"

/* Gets input board from text file and 
modifies board argument
*/
int get_board(char *dir, int board[][9])
{
    FILE *file;
    file = fopen(dir, "r");
    if (file == NULL)
    {
        printf("Invalid file path provided");
        return 1;
    }
    // This is probably dodgy because it has
    // no error handling for incorrectly
    // formated text file
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            int *location = &(board[y][x]);
            fscanf(file, "%d", location);
        }
    }
    fclose(file);
    return 0;
}

