#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define Base_ROW 9
#define Base_COL 9
#define ROW Base_ROW + 2
#define COL Base_COL + 2

void play(int difficultulty);
void InitMap(char map[ROW][COL], int row, int col, char ch);
void PrintMap(char map[ROW][COL], int row, int col, char ch);
int generate(char map[ROW][COL], int row, int col, int difficulty);
int Minesweeper(char bombMap[ROW][COL], char showMap[ROW][COL], int num);
void Unfold(char bombMap[ROW][COL], char showMap[ROW][COL], int x, int y);
