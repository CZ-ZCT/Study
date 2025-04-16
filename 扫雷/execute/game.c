#include "./../header/game.h"
void play(int difficulty)
{
    int res = -1; //记录游戏结果
    char bombMap[ROW][COL] = {0};
    char showMap[ROW][COL] = {0};
    InitMap(bombMap, ROW, COL, ' '); //初始化地雷分布图
    InitMap(showMap, ROW, ROW, '*'); //初始化地图
    // PrintMap(bombMap, Base_ROW, Base_COL, ' ');
    // PrintMap(showMap, Base_ROW, Base_COL, '*');
    int num = generate(bombMap, Base_ROW, Base_COL, difficulty); //生成地雷, num 为地雷数量
    // PrintMap(bombMap, Base_ROW, Base_COL, ' ');    
    
    while (1)
    {
        res = Minesweeper(bombMap, showMap, num);

        if (res != 0)
        {
            break;
        }
    }

    if (1 == res)
    {
        printf("游戏失败，你被雷炸死了！\n");
        PrintMap(bombMap, Base_ROW, Base_COL, ' ');
        system("pause");
        system("cls");
    }
    else
    {
        printf("恭喜你，游戏胜利！\n");
        system("pause");
        system("cls");
    }
    
    return;
}

void InitMap(char map[ROW][COL], int row, int col, char ch)
{
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            map[i][j] = ch;
        }
    }
}

void PrintMap(char map[ROW][COL], int row, int col, char ch)
{
    if (' ' == ch)
    {
        printf("==========地雷分布图==========\n");
    }

    printf("   ");
    for (int i=1; i<=col; ++i)
    {
        printf(" %d ", i);
    }
    printf("\n");

    printf("   ");
    for (int i=1; i<=col; ++i)
    {
        printf("---");
    }
    printf("\n");

    for (int i=0; i<row; ++i)
    {
        printf("%2d|", i+1);

        for (int j=0; j<col; ++j)
        {
            printf(" %c ", map[i+1][j+1]); //图的最外面一圈不需要打印
        }
        printf("\n");
    }
}

int  generate(char map[ROW][COL], int row, int col, int difficulty)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (i < difficulty * 10)
    {
        x = rand() % row + 1;
        y = rand() % col + 1;

        if (' ' == map[x][y])
        {
            map[x][y] = '1';
            ++i;
        }
    }

    return i;
}

int Minesweeper(char bombMap[ROW][COL], char showMap[ROW][COL], int num)
{
    int x = 0;
    int y = 0;

    PrintMap(showMap, Base_ROW, Base_COL, '*');
    printf("请输入排雷坐标：");

    while (scanf("%d %d", &x, &y) != 2 || (x < 1 || x > Base_ROW || y < 1 || y > Base_COL) || (showMap[x][y] != '*'))
    {
        while (getchar() != '\n');
        
        if (showMap[x][y] != '*')
        {
            printf("该坐标已经排除，请重新输入：");
        }
        else
        {
            printf("请输入正确的坐标：");
        }
    }

    system("cls");

    if ('1' == bombMap[x][y]) //踩雷，游戏失败
    {
        return 1; 
    }
    else
    {
        Unfold(bombMap, showMap, x, y);

        int count = 0;

        for (int i=1; i<=Base_ROW; ++i)
        {
            for (int j=1; j<=Base_COL; ++j)
            {
                if ('*' == showMap[i][j])
                {
                    ++count;
                }
            }
        }

        if (count > num)
        {
            return 0; //雷没有排完
        }
        else
        {
            return 2; //雷排完了

        }
    }
}

void Unfold(char bombMap[ROW][COL], char showMap[ROW][COL], int x, int y)
{
    int count = 0;

    for (int i=x-1; i<=x+1; ++i)
    {
        for (int j=y-1; j<=y+1; ++j)
        {
            if ('1' == bombMap[i][j])
            {
                ++count;
            }
        }
    }

    showMap[x][y] = count + '0';

    if (showMap[x][y] == '0')
    {
        for (int i=x-1; i<=x+1; ++i)
        {
            for (int j=y-1; j<=y+1; ++j)
            {
                if ('*' == showMap[i][j] && i >= 1 && i <= Base_ROW && j >= 1 && j <= Base_COL)
                {
                    Unfold(bombMap, showMap, i, j);
                }
            }
        }
    }
}
