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
    Init(&addressBook); //��ʼ��ͨѶ¼
    Loadcontacts(&addressBook); //������ϵ����Ϣ
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
            Savecontacts(&addressBook); //���ڴ��е�ͨѶ¼��Ϣ���浽�ļ���
            printf("Exit The Addressbook System!\n");
            break;
        case 1:
            Addcontacts(&addressBook); //������ϵ��
            break;
        case 2:
            Delcontacts(&addressBook); //ɾ����ϵ��
            break;
        case 3:
            Findcontacts(&addressBook); //������ϵ��
            break;
        case 4:
            Modifycontacts(&addressBook); //�޸���ϵ��
            break;
        case 5:
            Show(&addressBook); //��ӡͨѶ¼����
            break;
        case 6:
            Sortcontacts(&addressBook); //������ϵ��
            break;
        case 7:
            ExpansionCapacity(&addressBook); //����ͨѶ¼����
            break;
        default:
            break;
        }
    }while(choice != 0);
    
    free(addressBook.data);
    return 0;
}