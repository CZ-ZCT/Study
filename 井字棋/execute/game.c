#include "../header/game.h"
void play(int difficulty, int order)
{
    char my_choice = 0;

    char board[ROW][COL];
    char res = 0;
    
    do
    {
        initboard(board, ROW, COL);
        printboard(board, ROW, COL);

        if (order == 1) //�����������
        {
            while(1)
            {
                //�������
                playermove(board, ROW, COL);
                system("cls");
                //��ӡ����
                printboard(board, ROW, COL);
                //�ж���Ӯ
                res = check(board, ROW, COL);
                if( res != 'C') //�ж��Ƿ����
                {   
                    break;
                }
                Sleep(500);
                //4.��������
                if (1 == difficulty)
                {
                    computermove(board, ROW, COL);
                }
                else if (2 == difficulty)
                {
                    computermoveplus(board, ROW, COL);
                }
                system("cls");
                //5.��ӡ����
                printboard(board, ROW, COL);
                //6.�ж���Ӯ
                res = check(board, ROW, COL);
                if (res != 'C') //�ж��Ƿ����
                {
                    break;
                }
            }
        }
        else //������������
        {
            while(1)
            {
                //��������
                if (1 == difficulty)
                {
                    computermove(board, ROW, COL);
                }
                else if (2 == difficulty)
                {
                    computermoveplus(board, ROW, COL);
                }
                system("cls");
                //��ӡ����
                printboard(board, ROW, COL);
                //�ж���Ӯ
                res = check(board, ROW, COL);
                if (res != 'C') //�ж��Ƿ����
                {
                    break;
                }
                //�������
                playermove(board, ROW, COL);
                system("cls");
                //��ӡ����
                printboard(board, ROW, COL);
                //�ж���Ӯ
                res = check(board, ROW, COL);
                if( res != 'C') //�ж��Ƿ����
                {   
                    break;
                }
                Sleep(500);
            }
        }

        if ('O' == res)
        {
            printf("��Ӯ�ˣ�\n");
        }
        else if ('X' == res)
        {
            printf("�����ˣ�\n");
        }
        else
        {
            printf("ƽ�֣�\n");
        }
        
        printf("�Ƿ������Ϸ��(Y/N)");
        scanf(" %c", &my_choice);
        while (getchar() != '\n');

        while (my_choice != 'Y' && my_choice != 'N' && my_choice != 'y' && my_choice != 'n')
        {
            printf("�Ƿ�����!������Y/N:");
            scanf(" %c", &my_choice);
            while (getchar() != '\n');
        }
        system("cls");
    } while (my_choice == 'Y' || my_choice == 'y');
    
    system("cls");
}


void initboard(char board[ROW][COL], int row, int col)
{
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

void printboard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    
    for (i=0; i<=row; ++i)
    {
        for (j=0; j<col; ++j)
        {
            printf("----");
        }

        printf("\n");

        if (i < row)
        {
            for (j=0; j<col; ++j)
            {
                printf("| %c ", board[i][j]);
            }

            printf("|\n", board[i][j]);
        }
    }
}

void playermove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("����������λ��(�ÿո����):");
    
    while (scanf(" %d %d", &x, &y) != 2 || x < 1 || x > row || y < 1 || y > col || board[x-1][y-1] != ' ')
    {
        printf("����λ�ò��Ϸ�,����������:");
        while (getchar() != '\n');
    }

    board[x-1][y-1] = 'O';
}

int isEmpty(char board[ROW][COL], int row, int col)
{
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            if (' ' != board[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

void computermove(char board[ROW][COL], int row, int col)
{
    if (1 == isEmpty(board, ROW, COL)) //�������ǿ�ʱ������ռ����������
    {
        board[1][1] = 'X';
    }
    else
    {
        int x = 0;
        int y = 0;
        
        do
        {
            x = rand() % row + 1;
            y = rand() % col + 1;
        } while (board[x-1][y-1] != ' ');
        
        board[x-1][y-1] = 'X';
    }
}

void computermoveplus(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;

    //����ʹ�õ���Ӯ
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            if (' ' == board[i][j])
            {
                board[i][j] = 'X';
                
                if ('X' == check(board, ROW, COL))
                {
                    return;
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }
    
    //���Բ���Ӯ����ֹ���Ӯ
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            if (' ' == board[i][j])
            {
                board[i][j] = 'O';
                
                if ('O' == check(board, ROW, COL))
                {
                    board[i][j] = 'X';
                    return;
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }

    //�����Ժ������һ����û�а취Ӯ��ʱ���������
    computermove(board, ROW, COL);
}






char check(char board[ROW][COL], int row, int col)
{
    int flag = 0;

    for (int i=0; i<row; ++i)
    {
        flag = 1;

        for (int j=1; j<col; ++j)
        {
            if (board[i][0] != board[i][j] || board[i][0] == ' ')
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            return board[i][0];
        }
    }

    for (int j=0; j<col; ++j)
    {
        flag = 1;

        for (int i=1; i<row; ++i)
        {
            if (board[0][j] != board[i][j] || board[0][j] == ' ')
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            return board[0][j];
        }
    }

    for (int i=1; i<row; ++i)
    {
        if (board[i][i] == board[0][0] && board[0][0] != ' ')
        {
            flag = 1;
            continue;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        return board[0][0];
    }

    for (int i=1; i<row; ++i)
    {
        if (board[i][col-1-i] == board[0][col-1] && board[0][col-1] != ' ')
        {
            flag = 1;
            continue;
        }
        else
        {
            flag = 0;
            break;

        }
    }

    if (flag)
    {
        return board[0][col-1];
    }

    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            if (board[i][j] == ' ')
            {
                return 'C';
            }
        }
    }

    return 'P';
}

