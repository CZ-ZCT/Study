#include "./../header/game.h"

int menu()
{
    int choice = 0;
    printf("****************\n");
    printf("*    1.play    *\n");
    printf("*    2.exit    *\n");
    printf("****************\n");
    printf("���������ѡ��");

    while ((scanf(" %d", &choice) != 1 || (choice != 1 && choice != 2)))
    {
        printf("��������Чѡ�");
        while (getchar() != '\n');
    }

    system("cls");
    return choice;
}

void Loading()
{
    int count = 0;

    while (count <= 100)
    {
        printf("\r���ؽ���:%d%%", count);
        ++count;
        Sleep(5);
    }

    printf("\n�������!");
    Sleep(500);
    system("cls");
}

int ChooseDifficulty()
{
    int difficulty = 0;
    printf("****************\n");
    printf("*    1.��    *\n");
    printf("*    2.һ��    *\n");
    printf("*    3.����    *\n");
    printf("****************\n");
    printf("��ѡ����Ϸ�Ѷȣ�");

    while (scanf(" %d", &difficulty) != 1 || (difficulty != 1 && difficulty != 2 && difficulty != 3))
    {
        printf("��������Ч��ѡ��:");
        while(getchar() != '\n');
    }
    system("cls");
    return difficulty;
}


int main()
{
    int choice = 0;
    int difficulty = 0;
    srand((unsigned)time(NULL));

    do
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            //Loading();
            difficulty = ChooseDifficulty();
            play(difficulty);
            break;
        case 2:
            printf("��ӭ�´�������\n");
            system("pause");
            break; 
        default:
            break;
        }
    }
    while (choice != 2);

    return 0;
}