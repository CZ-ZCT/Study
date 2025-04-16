#include "./../header/addressbook.h"
void Init(AddressBook *paB)
{
    paB->data = (PeoMeg*)malloc(sizeof(PeoMeg) * MAXCAPACITY);

    if (paB->data == NULL)
    {
        printf("Memory allocation failed!\n");
       return;
    }

    memset(paB->data, 0, sizeof(PeoMeg) * MAXCAPACITY);
    paB->capacity = MAXCAPACITY;
    paB->size = 0;
    return ;
}