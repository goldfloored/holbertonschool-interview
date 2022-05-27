#include "sandpiles.h"
/**
  * print_grid - Print 3x3 grid
  * @grid: 2D array 3*3
  *
  */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
  * copy - copy of two sandpiles
  * @scr: 2D array
  * @des: 2D array
  */

void copy(int scr[3][3], int des[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			des[i][j] = scr[i][j];
		}
	}
}

/**
  * verif - test
  * @grid: 2D array
  * Return: 0
  */

int verif(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
  * sandpiles_sum - function that computes the sum of two sandpiles
  * @grid1: 2D array
  * @grid2: 2D array
  */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x;
	int y;
	int referenceGrid[3][3];
	int type = 0;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] = grid1[x][y] + grid2[x][y];
	type = verif(grid1);
	if (type == 1)
		return;
	printf("=\n");
	print_grid(grid1);
	while (type == 0)
	{
		copy(grid1, referenceGrid);
		for (x = 0; x < 3; x++)
			for (y = 0; y < 3; y++)
			{
				if (referenceGrid[x][y] > 3)
				{
					grid1[x][y] = grid1[x][y] - 4;
					if (x - 1 >= 0)
						grid1[x - 1][y] += 1;
					if (x + 1 <= 2)
						grid1[x + 1][y] += 1;
					if (y - 1 >= 0)
						grid1[x][y - 1] += 1;
					if (y + 1 <= 2)
						grid1[x][y + 1] += 1;
				}
			}
		type = verif(grid1);
		if (type == 1)
			break;
		printf("=\n");
		print_grid(grid1);
	}
}
