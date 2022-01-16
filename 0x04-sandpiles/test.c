#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

int main(void)
{
    int grid1[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int grid2[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };

    sandpiles_sum(grid1, grid2);

    return (EXIT_SUCCESS);
}
