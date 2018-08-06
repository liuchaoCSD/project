#define _CRT_SECURE_NO_WARNINGS_
#include"addr_book.h"

void AddrBookInit(AddrBook* addr_book)
{
	if (addr_book == NULL)
	{
		printf("addr_book is NULL\n");
		return;
	}
	addr_book->size = 0;
	addr_book->capacity = 1;
	addr_book->data = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
}
void AddrBookRelloc(AddrBook* addr_book)
{
	if (addr_book == NULL)
	{
		printf("addr_book is NULL\n");
		return; 
	}
	addr_book->capacity = addr_book->capacity * 2 + 1;
	PersonInfo* new_data = (PersonInfo*)malloc(addr_book->capacity*sizeof(PersonInfo));
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		new_data[i] = addr_book->data[i];
	}
	free(addr_book->data);
	addr_book->data = new_data;
}
void AddrBookAdd(AddrBook* addr_book)
{
	if (addr_book == NULL)
	{
		printf("addr_book is NULL\n");
		return;
	}
	if (addr_book->size >= addr_book->capacity)
	{
		AddrBookRelloc(addr_book);
	}
	size_t cur = addr_book->size;
	++addr_book->size;
	printf("开始插入数据:\n");
	printf("请输入姓名：\n");
	scanf_s("%s", addr_book->data[cur].name);
	printf("请输入电话：\n");
	scanf_s("%s", addr_book->data[cur].phone);
	printf("请输入地址：\n");
	scanf_s("%s", addr_book->data[cur].addr);
	printf("插入成功\n");
	return;
}
void AddrBookDisplay(AddrBook* addr_book)
{
	if (addr_book == NULL)
	{
		printf("addr_book is NULL\n");
		return;
	}
	printf("[姓名]\t\t[电话]\t\t[地址]\n");
	size_t i = 0;
	for (; i < addr_book->size; ++i)
	{
		printf("[%s]\t\t[%s]\t\t[%s]\n", addr_book->data[i].name, addr_book->data[i].phone, addr_book->data[i].addr);
	}
}
void Menu(){
	AddrBook addr_book;
	AddrBookInit(&addr_book);
	while (1){
		printf("=====================\n");

		printf("1.显示所有条目\n");
		printf("2.新增条目\n");
		printf("3.删除条目\n");
		printf("4.查找条目\n");
		printf("5.修改条目\n");
		printf("0. 退出通讯录\n");
		printf("=========================\n");
		int choice = 0;
		printf("请输入你的选项:\n");
		
		scanf_s("%d", &choice);
		
		switch (choice){
		case DISPLAY:
			AddrBookDisplay(&addr_book);
			break;
		case ADD:
			AddrBookAdd(&addr_book);
			break;
		case ERASE:
			break;
		case FIND:
			break;
		case MODIFY:
			break;
		case EXIT:
			break;
		default:
			printf("非法输入！ 请你重新输入\n");
			break;
		}
	}
}
int main()
{
	Menu();
	return;
}