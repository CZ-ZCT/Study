#include "./../header/addressbook.h"
void Show(const AddressBook *paB)
{
    if (paB->size == 0)
    {
        printf("The addressbook is enpty!\n");
        return ;
    }
    else
    {
        printf("%-10s\t%-5s\t%-12s\t%-20s\n", "name", "sex","tel","email");

        for (int i=0; i<paB->size; ++i)
        {
            printf("%-10s\t%-5s\t%-12s\t%-20s\n", paB->data[i].name,
                                                  paB->data[i].sex, 
                                                  paB->data[i].tel, 
                                                  paB->data[i].email);
        }

        return ;
    }
}