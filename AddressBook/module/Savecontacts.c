#include "./../header/addressbook.h"

void Savecontacts(const AddressBook *paB)
{
    if (paB != NULL)
    {
        //打开文件
        FILE *pf = fopen("E:/Code/C++/VSCode/AddressBook/Contacts.txt","w");

        if (pf == NULL)
        {
            perror("fopen");
        }
        else
        {
            for (int i=0; i<paB->size; ++i)
            {
                // fputs(((paB->data)+i)->name, pf);
                // fputs(((paB->data)+i)->sex, pf);
                // fputs(((paB->data)+i)->tel, pf);
                // fputs(((paB->data)+i)->email, pf);
                // fputs("\n", pf);
                fprintf(pf, "%-10s\t%-5s\t%-12s\t%-20s\n", paB->data[i].name,
                                                           paB->data[i].sex,
                                                           paB->data[i].tel,
                                                           paB->data[i].email);
            }
            
        }

        //关闭文件
        fclose(pf);
        pf = NULL;
        return;
    }
    else
    {
        return ;
    }
}