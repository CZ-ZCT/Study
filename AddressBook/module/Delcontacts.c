#include "./../header/addressbook.h"

static int FindByName(AddressBook *paB, char *name)
{
    for (int i=0; i<paB->size; ++i)
    {
        if (strcmp(name, paB->data[i].name) == 0)
        {
            return i;
        }
    }

    return -1;
}


void Delcontacts(AddressBook *paB)
{
    if (0 == paB->size)
    {
        printf("The addressbook is empty!\n");
    }
    else
    {
        char name[NAMESIZE] = {0};
        printf("Please enter the name of the contact to be deleted:");
        scanf("%s", name);

        //1.按照姓名查找联系人在通讯录中的位置
        int location = FindByName(paB, name);
        
        if (location < 0)
        {
            printf("%s does not exist.\n", name);
            return ;
        }
        //2.根据上面的位置删除联系人
        else
        {
            memmove((paB->data)+location, (paB->data)+location+1, ((paB->size)- location - 1) * sizeof(PeoMeg));
            
            // for (int i=location; i<paB->size-1; ++i)
            // {
            //     paB->data[i] = paB->data[i+1];
            // }

            --(paB->size);
            printf("%s is deleted.\n", name);
            return ;
        }
    }
}