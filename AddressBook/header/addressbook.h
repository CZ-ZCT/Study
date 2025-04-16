#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <errno.h>

#define NAMESIZE 10  //姓名最大长度
#define SEXSIZE 5    //性别最大长度
#define TELSIZE 12   //电话号码最大长度
#define EMAILSIZE 20 //电子邮箱地址最大长度
#define MAXCAPACITY 3  //通讯库最大容量

typedef struct PeopleMessage
{
    char name[NAMESIZE];
    char sex[SEXSIZE];
    char tel[TELSIZE];
    char email[EMAILSIZE];
}PeoMeg;

typedef struct AddressBook
{
    PeoMeg *data;
    int capacity; //总容量
    int size; //通讯录已经保存的联系人的数量
}AddressBook;

void Menu(); //显示主菜单
void Init(AddressBook *paB); //初始化通讯录
void Addcontacts(AddressBook *paB); //新增联系人
void Show(const AddressBook *paB); //打印通讯录
void Delcontacts(AddressBook *paB); //删除联系人
void Findcontacts(const AddressBook *paB); //查找联系人信息
void Modifycontacts(AddressBook *paB); //修改联系人
void Sortcontacts(AddressBook *paB); //排序联系人
void ExpansionCapacity(AddressBook *paB); //扩大通讯录空间
void Savecontacts(const AddressBook *pB); //将内存中的通讯录信息保存到文件里
void Loadcontacts(AddressBook *pB); //将文件里的联系人信息加载到内存里