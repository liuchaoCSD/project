#include<stdio.h>
#include<stdlib.h>
#define HEAD printf("=====%s=====",__FUNCTION__);
typedef char DataType;

typedef struct linkStack{
	DataType data;
	struct likStack* next;
}linkStack;
void linkStackInit(linkStack** head);
linkStack* Creatnode(DataType data);
void linkStackPush(linkStack** head, DataType data);
void linkStackPrint(linkStack* head, char* msg);
void linkStackPop(linkStack** head);
DataType linkStackTop(linkStack* head);
void linkDestroy(linkStack **head);