#include "./../header/addressbook.h"

void ExpansionCapacity(AddressBook *paB)
{
    PeoMeg * newdata = (PeoMeg*)realloc(paB->data, (MAXCAPACITY + paB->size) * sizeof(PeoMeg));

    if (newdata == NULL)
    {
        printf("Expansion Capacity Fault!\n");
        return ;
    }
    else
    {
        paB->data = newdata;
        newdata = NULL;
        memset((paB->data)+(paB->size), 0, MAXCAPACITY * (sizeof(PeoMeg)));
        paB->capacity = (paB->capacity) + MAXCAPACITY;
        printf("Expansion Capacity successfully!\n");
        return ;
    }
}