#include ".\..\header\addressbook.h"
void Addcontacts(AddressBook *paB)
{
    if ((paB->size) == paB->capacity)
    {
        printf("The address book is full, please delete contacts or expansion capacity.\n");
        return ;
    }
    else
    {
        printf("Plese input name of the new contact:");
        scanf("%s", paB->data[paB->size].name);
        printf("Plese input sex of the new contact:");
        scanf("%s", paB->data[paB->size].sex);
        printf("Plese input phonenumber of the new contact:");
        scanf("%s", paB->data[paB->size].tel);
        printf("Plese input email of the new contact:");
        scanf("%s", paB->data[paB->size].email);
        ++(paB->size);
        printf("Addcontacts Successfully!\n");
        return ;
    }
}