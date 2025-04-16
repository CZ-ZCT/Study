#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 3
#define COL 3

void play(int order, int difficulty);
void initboard(char board[ROW][COL], int row, int col);
void printboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
void computermoveplus(char board[ROW][COL], int row, int col);
void computermoveplusplus(char board[ROW][COL], int row, int col);
char check(char board[ROW][COL], int row, int col);
int isEmpty(char board[ROW][COL], int row, int col);

