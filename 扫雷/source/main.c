#include "./../header/game.h"

int menu()
{
    int choice = 0;
    printf("****************\n");
    printf("*    1.play    *\n");
    printf("*    2.exit    *\n");
    printf("****************\n");
    printf("请输入你的选择：");

    while ((scanf(" %d", &choice) != 1 || (choice != 1 && choice != 2)))
    {
        printf("请输入有效选项：");
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
        printf("\r加载进度:%d%%", count);
        ++count;
        Sleep(5);
    }

    printf("\n加载完成!");
    Sleep(500);
    system("cls");
}

int ChooseDifficulty()
{
    int difficulty = 0;
    printf("****************\n");
    printf("*    1.简单    *\n");
    printf("*    2.一般    *\n");
    printf("*    3.困难    *\n");
    printf("****************\n");
    printf("请选择游戏难度：");

    while (scanf(" %d", &difficulty) != 1 || (difficulty != 1 && difficulty != 2 && difficulty != 3))
    {
        printf("请输入有效的选项:");
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
            printf("欢迎下次再来！\n");
            system("pause");
            break; 
        default:
            break;
        }
    }
    while (choice != 2);

    return 0;
}