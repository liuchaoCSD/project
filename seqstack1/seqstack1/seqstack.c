#include"seqstack.h"
void linkStackInit(linkStack** head)
{
	*head = NULL;
}
linkStack* Creatnode(DataType data)
{
	linkStack* new_node = (linkStack*)malloc(sizeof(DataType));
	new_node->data = data;
	return new_node;
}
void linkStackPush(linkStack** head, DataType data)
{
	if (head == NULL)
	{
		return;
	}
	linkStack *new_node = Creatnode(data);
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next == NULL;
		return;
	}
	linkStack *temp = *head;
	new_node->next = temp;
	*head=new_node;
} 
void linkStackPrint(linkStack* head, char* msg)
{
	printf("\n[%s]\n", msg);
	if (head == NULL)
	{
		return;
	}
	linkStack* temp = head;
	while (temp != NULL)
	{
		printf("[%c|%9p]\n", temp->data, temp->next);
		temp = temp->next;
	}
	return 0;
}

void linkStackPop(linkStack** head)
{
	if (head == NULL)
	{
		return;//·Ç·¨ÊäÈë
	}
	if (*head == NULL)
	{
		return;//kong
	}
	linkStack *temp = *head;
	*head = temp->next;
//	free(temp);
}
DataType linkStackTop(linkStack* head)
{
	if (head == NULL)
	{
		return;
	}
	linkStack *temp = head;
	return temp->data;
}
void linkDestroy(linkStack **head)
{
	if (head == NULL)
	{
		return;
	}
	if (*head == NULL)
	{
		return;
	}
	linkStack *temp = *head;
	linkStack *cur = NULL;
	while (temp != NULL)
	{
		cur = temp->next;
		free(temp);
		temp = cur;
	}
	head = NULL;
	*head == NULL;
}