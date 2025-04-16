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

void Modifycontacts(AddressBook *paB)
{
    char name[NAMESIZE] = {0};
    printf("Enter the name of the contact to be modified:");
    scanf("%s", name);

    int location = FindByName(paB, name);

    if (location < 0)
    {
        printf("%s is not exit!\n", name);
        return ;
    }
    else
    {
        printf("Plese input name of the new contact:");
        scanf("%s", paB->data[location].name);
        printf("Plese input sex of the new contact:");
        scanf("%s", paB->data[location].sex);
        printf("Plese input phonenumber of the new contact:");
        scanf("%s", paB->data[location].tel);
        printf("Plese input email of the new contact:");
        scanf("%s", paB->data[location].email);

        printf("Modify Successsfully!\n");
        return ;
    }
}