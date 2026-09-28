#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "game.h"
#include "utilityFunctions.h"

void newGame(int* board, int size, int bestScore, int* currentScore)  // Restarts the game by initializing the board
{
	initalizeBoard(board, size);
	generateRandomNum(board, size);
	generateRandomNum(board, size);
	
	*currentScore = 0;

	printf("Current Score: 0 | Best Score: %d\n", bestScore);

	printBoard(board, size);
}

void moveRight(int* board, int size, int* currentScore)  // Handles moving all numbers to the right, combining when necessary
{
	int switchCount = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > 0; j--)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (*(board + i * size + j) == 0 && *(board + i * size + k) != 0)
				{
					*(board + i * size + j) = *(board + i * size + k);
					*(board + i * size + k) = 0;
					switchCount++;
					break;
				}
			}
		}

		for (int j = size - 1; j > 0; j--)
		{
			if (*(board + i * size + j) == *(board + i * size + j - 1) && *(board + i * size + j) != 0)
			{
				*(board + i * size + j) *= 2;
				*(board + i * size + j - 1) = 0;
				*currentScore += *(board + i * size + j);
				switchCount++;
				break;
			}
		}

		for (int j = size - 1; j > 0; j--)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (*(board + i * size + j) == 0 && *(board + i * size + k) != 0)
				{
					*(board + i * size + j) = *(board + i * size + k);
					*(board + i * size + k) = 0;
					switchCount++;
					break;
				}
			}
		}
	}

	if (switchCount > 0)
		generateRandomNum(board, size);
	else
		printf("Nothing to move here!\n");
}

void moveLeft(int* board, int size, int* currentScore)   // Handles moving all numbers to the left, combining when necessary
{
	int switchCount = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				if (*(board + i * size + j) == 0 && *(board + i * size + k) != 0)
				{
					*(board + i * size + j) = *(board + i * size + k);
					*(board + i * size + k) = 0;
					switchCount++;
					break;
				}
			}
		}

		for (int j = 0; j < size - 1; j++)
		{
			if (*(board + i * size + j) == *(board + i * size + j + 1) && *(board + i * size + j) != 0)
			{
				*(board + i * size + j) *= 2;
				*(board + i * size + j + 1) = 0;
				*currentScore += *(board + i * size + j);
				switchCount++;
				break;
			}
		}

		for (int j = 0; j < size - 1; j++)
		{
			for (int k = j + 1; k <= size - 1; k++)
			{
				if (*(board + i * size + j) == 0 && *(board + i * size + k) != 0)
				{
					*(board + i * size + j) = *(board + i * size + k);
					*(board + i * size + k) = 0;
					switchCount++;
					break;
				}
			}
		}
	}

	if (switchCount > 0)
		generateRandomNum(board, size);
	else
		printf("Nothing to move here!\n");
}

void moveUp(int* board, int size, int* currentScore)  // Handles moving all numbers up, combining when necessary
{
	int switchCount = 0;

	for (int j = 0; j < size; j++)
	{

		for (int i = 0; i < size - 1; i++)
		{
			for (int k = i + 1; k < size; k++)
			{
				if (*(board + i * size + j) == 0 && *(board + k * size + j) != 0)
				{
					*(board + i * size + j) = *(board + k * size + j);
					*(board + k * size + j) = 0;
					*currentScore += *(board + i * size + j);
					switchCount++;
					break;
				}
			}
		}

		for (int i = 0; i < size - 1; i++)
		{
			if (*(board + i * size + j) == *(board + (i + 1) * size + j) && *(board + i * size + j) != 0)
			{
				*(board + i * size + j) *= 2;
				*(board + (i + 1) * size + j) = 0;
				switchCount++;
				break;
			}
		}

		for (int i = 0; i < size - 1; i++)
		{
			for (int k = i + 1; k < size; k++)
			{
				if (*(board + i * size + j) == 0 && *(board + k * size + j) != 0)
				{
					*(board + i * size + j) = *(board + k * size + j);
					*(board + k * size + j) = 0;
					switchCount++;
					break;
				}
			}
		}
	}

	if (switchCount > 0)
		generateRandomNum(board, size);
	else
		printf("Nothing to move here!\n");
}

void moveDown(int* board, int size, int* currentScore)  // Handles moving all numbers down, combining when necessary
{
	int switchCount = 0;

	for (int j = 0; j < size; j++)
	{

		for (int i = size - 1; i > 0; i--)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (*(board + i * size + j) == 0 && *(board + k * size + j) != 0)
				{
					*(board + i * size + j) = *(board + k * size + j);
					*(board + k * size + j) = 0;
					switchCount++;
					break;
				}
			}
		}

		for (int i = size - 1; i > 0; i--)
		{
			if (*(board + i * size + j) == *(board + (i - 1) * size + j) && *(board + i * size + j) != 0)
			{
				*(board + i * size + j) *= 2;
				*(board + (i - 1) * size + j) = 0;
				*currentScore += *(board + i * size + j);
				switchCount++;
				break;
			}
		}

		for (int i = size - 1; i > 0; i--)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (*(board + i * size + j) == 0 && *(board + k * size + j) != 0)
				{
					*(board + i * size + j) = *(board + k * size + j);
					*(board + k * size + j) = 0;
					switchCount++;
					break;
				}
			}
		}
	}

	if (switchCount > 0)
		generateRandomNum(board, size);
	else
		printf("Nothing to move here!\n");
}

int hasLost(int* board, int size)  // Checks if the player has lost the game
{
	if (emptyCells(board, size) != 0)  // If we have empty cells, return false.
		return 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)  // If we can combine numbers, return false.
		{
			if (j < size - 1 && *(board + i * size + j) == *(board + i * size + j + 1))
				return 0;

			if (i < size - 1 && *(board + i * size + j) == *(board + (i + 1) * size + j))
				return 0;
		}
	}
	return 1;  // If we passed all tests, then the board is full and we have nowhere to move. Return true.
}

int highestTile(int* board, int size)  // Returns the highest tile in the board (Used to check if a player has won)
{
	int highest = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (*(board + i * size + j) > highest)
				highest = *(board + i * size + j);
		}
	}
	return highest;
}


void playGame(int* board, int size, int scoreToWin)
{
	int bestScore = 0;
	int currentScore = 0;
	int gameStarted = 0;  // Flag to determine if a game is active

	initalizeBoard(board, size);
	printBoard(board, size);
	printMenu();

	char option;
	scanf("%c", &option);
	while (getchar() != '\n');  // Clean buffer
	option = tolower(option);

	while (option != 'e')
	{
		if (option == 'n')
		{
			newGame(board, size, bestScore, &currentScore);
			gameStarted = 1;
		}

		else if (gameStarted != 1)
		{
			printBoard(board, size);
			printf("\n\nInvalid Option! Need to start a game first.\n");
		}

		else
		{
			if (option == 'r')
			{
				moveRight(board, size, &currentScore);

			}
			else if (option == 'l')
			{
				moveLeft(board, size, &currentScore);

			}
			else if (option == 'u')
			{
				moveUp(board, size, &currentScore);

			}
			else if (option == 'd')
			{
				moveDown(board, size, &currentScore);

			}
			else
			{
			        printf("\n\nInvalid Option!\n\n");
			}

			if (currentScore > bestScore)
				bestScore = currentScore;  // Updating currentScore to bestScore if needed

			printf("Current Score: %d | Best Score: %d\n", currentScore, bestScore);
			printBoard(board, size);

			if (highestTile(board, size) >= scoreToWin)
			{
				printf("You win!\n");
				initalizeBoard(board, size);
				gameStarted = 0;
			}

			else if (hasLost(board, size) == 1)
			{
				printf("You lost!\n");
				initalizeBoard(board, size);
				gameStarted = 0;
			}
		}

		printMenu();

		scanf("%c", &option);
		while (getchar() != '\n');  // Clean buffer
		option = tolower(option);
	}
	printf("Ending your previous game - Your score: %d | Best score: %d\n\n", currentScore, bestScore);  // If player clicked "e"
}
