#include"seqstack.h"
void Test()
{
	linkStack* myStack;
	linkStackInit(&myStack);
	linkStackPush(&myStack, 'a');
	linkStackPush(&myStack, 'b');
	linkStackPush(&myStack, 'c');
	linkStackPush(&myStack, 'd');
	linkStackPop(&myStack);
int ret=	linkStackTop(&myStack);
	linkStackPrint(myStack, "��ջ�ĸ�Ԫ��");
	linkStackPop(&myStack);
	
}
int main()
{
	HEAD;
	Test();
	printf("\n");
	return 0;
}