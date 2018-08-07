#include"seqstack6.h"
void SharestackInit(Sharestack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	stack->top1 = -1;
	stack->top2 = MAX_SIZE;
}
void SharestackPush(Sharestack* stack, int stateNum, DataType data)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->top1 + 1 == stack->top2)
	{
		printf("栈已经满了，你不能再入栈了\n");
		return;
	}
	if (stateNum == 1)
	{
		stack->data[++stack->top1]=data;
	}
	if (stateNum == 2)
	{
		stack->data[--stack->top2]=data;
    }
}
void SharestackPop(Sharestack* stack, int stateNum)
{
	if (stack == NULL)
	{
		return;
	}
	if (stateNum == 1)
	{
		if (stack->top1 == -1)
		{
			return;
		}
		--stack->top1;
	}
	if (stateNum == 2)
	{
		if (stack->top2==MAX_SIZE)
		{
		return;		
         }
		++stack->top2;
	}
}
void SharestackPrintf(Sharestack* stack, const char* msg)
{
	printf("=====%s=====\n", msg);
	if (stack == NULL)
	{
		return;
	}
	printf("======top1======\n");
	for (int i = stack->top1; i >= 0; i--)
	{
		printf("[%c]\n", stack->data[i]);
	}
	printf("=======top2======\n");
	for (int i = stack->top2; i < MAX_SIZE; i++)
	{
		printf("[%c]\n", stack->data[i]);
	}
}
 void Test()
{
	Sharestack stack;
	SharestackInit(&stack);
	SharestackPush(&stack, 1,'a');
	SharestackPush(&stack, 1, 'b');
	SharestackPush(&stack, 1, 'c');
	SharestackPush(&stack, 1, 'd');
	SharestackPush(&stack, 2, 'e');
	SharestackPush(&stack, 2, 'f');
	SharestackPush(&stack, 2, 'g');
	SharestackPush(&stack, 2, 'h');
	SharestackPrintf(&stack, "进入共享栈");
	SharestackPop(&stack, 1);
	SharestackPop(&stack, 1);
	SharestackPrintf(&stack, "出栈两个元素");
	SharestackPop(&stack, 2);
	SharestackPop(&stack, 2);
	SharestackPrintf(&stack, "出栈两个元素");
    }
int main()
{
	Test();
	return 0;

}

