#include "./../header/addressbook.h"
void Loadcontacts(AddressBook *paB)
{
    //打开文件
    FILE *pf = fopen("E:/Code/C++/VSCode/AddressBook/Contacts.txt", "r");

    if (pf == NULL)
    {
        perror("fopen");
        pf = NULL;
        return ;
    }
    else
    {
        while (fscanf(pf, "%s %s %s %s", paB->data[paB->size].name,
                                         paB->data[paB->size].sex,
                                         paB->data[paB->size].tel,
                                         paB->data[paB->size].email) != EOF)
        {
            ++(paB->size);

            if (paB->size == paB->capacity)
            {
                PeoMeg *newdata= (PeoMeg*)realloc(paB->data,  (MAXCAPACITY + paB->size) * sizeof(PeoMeg));

                if (newdata == NULL)
                {
                    printf("Loadcontacts Fault!\n");
                    return ;
                }
                else
                {
                    paB->data = newdata;
                    newdata = NULL;
                    memset((paB->data)+paB->size, 0, MAXCAPACITY * sizeof(PeoMeg));
                    paB->capacity = paB->capacity + MAXCAPACITY;
                }
            }
        }
    }

    //关闭文件
    fclose(pf);
    pf = NULL;
}