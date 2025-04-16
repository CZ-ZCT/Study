#include "./../header/addressbook.h"

static int Find(const AddressBook *paB, const char *str)
{
    for (int i=0; i<paB->size; ++i)
    {
        if ((strcmp(str, paB->data[i].name)==0)
            || (strcmp(str, paB->data[i].tel) == 0) 
            || (strcmp(str, paB->data[i].email) == 0))
            {
                return i;
            }
    }

    return -1;
}


void Findcontacts(const AddressBook *paB)
{
    char str[20] = {0};
    printf("Input contact's name or phonenumber or email:");
    scanf("%s", str);
    int location = Find(paB, str);

    if (location < 0)
    {
        printf("Not Found.\n");
        return ;
    }
    else
    {
        printf("%-10s\t%-5s\t%-12s\t%-20s\n", "name", "sex","tel","email");
        printf("%-10s\t%-5s\t%-12s\t%-20s\n", paB->data[location].name,
                                              paB->data[location].sex, 
                                              paB->data[location].tel, 
                                              paB->data[location].email);
        return ;
    }
}