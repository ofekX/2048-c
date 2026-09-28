#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "utilityFunctions.h"

void printMenu()  // Prints the menu
{
	printf("\n\nPlease choose one of the following options:\n");
	printf("N/n - New Game\n");
	printf("R/r - Move Right\n");
	printf("L/l - Move Left\n");
	printf("U/u - Move Up\n");
	printf("D/d - Move Down\n");
	printf("E/e - Exit\n");
}

void initalizeBoard(int* board, int size)  // Fills the board with 0 in all tiles
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(board + i * size + j) = 0;
		}
	}
}

int numDigits(int num)  // Returns the number of digits of a number
{
	int count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

void printBoard(int* board, int size)  // Prints the board
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size * 4 + size + 1; j++)
		{
			printf("-");
		}
		printf("\n");

		for (int j = 0; j < size; j++)
		{
			int num = *(board + i * size + j);
			printf("|");
			for (int w = 0; w < 4 - numDigits(num); w++)
			{
				printf(" ");
			}
			if (num != 0)
				printf("%d", num);
		}
		printf("|");
		printf("\n");
	}
	for (int i = 0; i < size * 4 + size + 1; i++)
	{
		printf("-");
	}
	printf("\n");
}

int emptyCells(int* board, int size)  // Returns the number of empty tiles in the board
{
	int emptyCount = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (*(board + i * size + j) == 0)
				emptyCount++;
		}
	}
	return emptyCount;
}

void generateRandomNum(int* board, int size)  // Generates a random number (2 or 4)
{
	int randomRow = rand() % size;
	int randomCol = rand() % size;
	while (*(board + randomRow * size + randomCol) != 0)
	{
		randomRow = rand() % size;
		randomCol = rand() % size;
	}
	int randomNumber = (rand() % 10 < 7) ? 2 : 4;  // Generate 2 in a rate of 0.7 and 4 in a rate of 0.3
	*(board + randomRow * size + randomCol) = randomNumber;  // Place the number inside a random tile
}
