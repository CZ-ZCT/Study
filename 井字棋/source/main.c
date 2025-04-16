#include "../header/game.h"

void clear()
{
    int ch = 0;

    while ((ch=getchar()) != EOF)
    {
        if (ch == '\n')
        {
            break;
        }
    }

}

void Loading()
{
    int count = 0;

    while (count <= 100)
    {
        printf("\r���ؽ���:%d%%", count);
        ++count;
        Sleep(10);
    }

    printf("\n�������!");
    Sleep(500);
    system("cls");
}


int menu()
{
    int choice = 0;
    printf("****************\n");
    printf("*    1.play    *\n");
    printf("*    2.exit    *\n");
    printf("****************\n");
    printf("���������ѡ��");

    while (scanf(" %d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        printf("��������Ч��ѡ�");
        clear();
    }

    return choice;
}
int chooseOrder()
{
    int order = 0;
    printf("****************\n");
    printf("*    1.����    *\n");
    printf("*    2.����    *\n");
    printf("****************\n");
    printf("���������ѡ��");

    while (scanf(" %d", &order) != 1 || (order != 1 && order != 2))
    {
        printf("��������Ч��ѡ��:");
        clear();
    }
    system("cls");
    return order;
}

int chooseDifficulty()
{
    int difficulty = 0;
    printf("****************\n");
    printf("*    1.��    *\n");
    printf("*    2.һ��    *\n");
    printf("****************\n");
    printf("���������ѡ��");

    while (scanf(" %d", &difficulty) != 1 || (difficulty != 1 && difficulty != 2))
    {
        printf("��������Ч��ѡ��:");
        clear();
    }
    system("cls");
    return difficulty;
}

int main()
{
    int choice = 0;
    srand((unsigned int)time(NULL));

    do
    {
        choice = menu();

        switch (choice)
        {
            case 1:
                Loading();
                int difficulty = chooseDifficulty();
                int order = chooseOrder();
                play(difficulty, order);
                break;
            case 2:
                printf("��ӭ�´�������\n");
                break;
            default:
                break;
        }
    } while (choice != 2);
    
    return 0;
}