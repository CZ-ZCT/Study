#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <errno.h>

#define NAMESIZE 10  //������󳤶�
#define SEXSIZE 5    //�Ա���󳤶�
#define TELSIZE 12   //�绰������󳤶�
#define EMAILSIZE 20 //���������ַ��󳤶�
#define MAXCAPACITY 3  //ͨѶ���������

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
    int capacity; //������
    int size; //ͨѶ¼�Ѿ��������ϵ�˵�����
}AddressBook;

void Menu(); //��ʾ���˵�
void Init(AddressBook *paB); //��ʼ��ͨѶ¼
void Addcontacts(AddressBook *paB); //������ϵ��
void Show(const AddressBook *paB); //��ӡͨѶ¼
void Delcontacts(AddressBook *paB); //ɾ����ϵ��
void Findcontacts(const AddressBook *paB); //������ϵ����Ϣ
void Modifycontacts(AddressBook *paB); //�޸���ϵ��
void Sortcontacts(AddressBook *paB); //������ϵ��
void ExpansionCapacity(AddressBook *paB); //����ͨѶ¼�ռ�
void Savecontacts(const AddressBook *pB); //���ڴ��е�ͨѶ¼��Ϣ���浽�ļ���
void Loadcontacts(AddressBook *pB); //���ļ������ϵ����Ϣ���ص��ڴ���