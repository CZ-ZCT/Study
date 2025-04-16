#include "./header/addressbook.h"
static void clean()
{
    char ch = getchar();

    while (ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }
}


int main()
{
    AddressBook addressBook;
    Init(&addressBook); //初始化通讯录
    Loadcontacts(&addressBook); //加载联系人信息
    int choice = 0;

    do
    {
        Menu();
        printf("Input Your Option:");

        while ((scanf("%d", &choice) != 1) || choice < 0 || choice > 7)
        {
            printf("Please Input Correct Option:");
            clean();
        }

        switch (choice)
        {
        case 0:
            Savecontacts(&addressBook); //将内存中的通讯录信息保存到文件里
            printf("Exit The Addressbook System!\n");
            break;
        case 1:
            Addcontacts(&addressBook); //新增联系人
            break;
        case 2:
            Delcontacts(&addressBook); //删除联系人
            break;
        case 3:
            Findcontacts(&addressBook); //查找联系人
            break;
        case 4:
            Modifycontacts(&addressBook); //修改联系人
            break;
        case 5:
            Show(&addressBook); //打印通讯录内容
            break;
        case 6:
            Sortcontacts(&addressBook); //排序联系人
            break;
        case 7:
            ExpansionCapacity(&addressBook); //扩充通讯录容量
            break;
        default:
            break;
        }
    }while(choice != 0);
    
    free(addressBook.data);
    return 0;
}