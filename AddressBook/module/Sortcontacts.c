#include "./../header/addressbook.h"

static int CompareByName(const void *el1, const void *el2)
{
    return strcmp(((PeoMeg*)el1)->name, ((PeoMeg*)el2)->name);
}
void Sortcontacts(AddressBook *paB)
{
    if (0 == paB->size)
    {
        printf("The addressbook is empty!\n");
        return ;
    }
    else
    {
        qsort(paB->data, paB->size, sizeof(PeoMeg), CompareByName);
        printf("Sort Successfully!\n");
        return ;
    }
}