#ifndef __GAME__
#define __GAME__

void newGame(int* board, int size, int bestScore, int* currentScore);
void moveRight(int* board, int size, int* currentScore);
void moveLeft(int* board, int size, int* currentScore);
void moveDown(int* board, int size, int* currentScore);
void moveUp(int* board, int size, int* currentScore);
void playGame(int* board, int size, int scoreToWin);

#endif
