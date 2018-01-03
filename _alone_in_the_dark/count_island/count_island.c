// #include <island.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	filling(char fill, char **matrix, int x, int y);

int		main(void)
{
	int 	num;
	char	**matrix;

	matrix = malloc(sizeof(char *) * 15);
	matrix[0] =  strdup("...................................................................");
	matrix[1] =  strdup("...X........X.....XXXXX......XXXXXXX...XXXXXXXXXX..XXXXXXXXXX......");
	matrix[2] =  strdup("...XX......XX....XX...XX....XX.....XX.....XXXX.....XXXXXXXXXX......");
	matrix[3] =  strdup("...XXXX..XXXX...XX.....XX...XX.....XX......XX......XX..............");
	matrix[4] =  strdup("...XX.XXXX.XX...XX.....XX...XX.....XX......XX......XX..............");
	matrix[5] =  strdup("...XX...X..XX...XX.....XX...XXXXXXXX.......XX......XXXXX...........");
	matrix[6] =  strdup("...XX......XX...XXXXXXXXX...XXXX...........XX......XXXXX...........");
	matrix[7] =  strdup("...XX......XX..XX.......XX..XX.XX..........XX......XX..............");
	matrix[8] =  strdup("...XX......XX..XX.......XX..XX...X.........XX......XX..............");
	matrix[9] =  strdup("...XX......XX..XX.......XX..XX....X......XXXXXX....XXXXXXXXXX......");
	matrix[10] = strdup("...XX......XX.XX.........XX.XX.....XX..XXXXXXXXXX..XXXXXXXXXX..X...");
	matrix[11] = strdup("...................................................................");
	matrix[12] = NULL;

	printf("INPUT:\n");
	for (int i = 0; matrix[i]; i++)
	{
		for (int j = 0; matrix[i][j]; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}

	char	fill = '0';
	for (int i = 0; matrix[i]; i++)
	{
		for (int j = 0; matrix[i][j]; j++)
		{
			if (matrix[i][j] == 'X')
				filling(fill++, matrix, i, j);
		}
	}

	printf("OUTPUT:\n");
	for (int i = 0; matrix[i]; i++)
	{
		for (int j = 0; matrix[i][j]; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}
	return (0);
}

void	filling(char fill, char **matrix, int x, int y)
{
	if (x >= 0 && matrix[x] && y >= 0 && matrix[x][y])
	{
		if (matrix[x][y] != 'X')
			return ;
		else
			matrix[x][y] = fill;
		filling(fill, matrix, x + 1, y);
		filling(fill, matrix, x - 1, y);
		filling(fill, matrix, x, y - 1);
		filling(fill, matrix, x, y + 1);
	}
}