#include"seqstack2.h"
#define TEST printf("========%s========\n",__FUNCTION__);
void SeqstackInit(Seqstack* stack)
{
	stack->data = (StackType*)malloc(sizeof(StackType)*DEFAULT);
	stack->size = 0;
	stack->capacity = DEFAULT;
}
void SeqstackPrint(Seqstack* stack, const char* msg)
{
	printf("\n===%s====\n", msg);
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	for (int i = stack->size - 1; i >= 0;--i)
	{
		printf("[%c]\n",stack->data[i]);
	}
	printf("\n");
}
void SeqstackPush(Seqstack* stack, StackType data)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == stack->capacity)
	{
		//栈满需要扩容
		StackType* ptr = (StackType*)realloc(stack->data, sizeof(StackType)*stack->capacity * 2 + 1);
		stack->data = ptr;
	}
	if (data <= stack->data[stack->size - 1] || stack->size == 0)
	{
		stack->data[stack->size ] = data;
		++stack->size;
		stack->data[stack->size] = data;
		++stack->size;
	}
	else {
		//如果大于栈顶元素，则先入此元素再入栈顶元素
		StackType min = stack->data[stack->size - 1];
		stack->data[stack->size] = data;
		++stack->size;
		stack->data[stack->size] = min;
		++stack->size;
	}
}
StackType* Seqstackmin(Seqstack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}		
	if (stack->size == 0)
		{
			return NULL;
		}
		return &(stack->data[stack->size - 1]);
	}
void SeqstackPop(Seqstack* stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}
	--stack->size;
	--stack->size;
}
TestPush()
{
	TEST;
	Seqstack stack;
	SeqstackInit(&stack);
	SeqstackPush(&stack, 'd');
	SeqstackPush(&stack, 'f');
	SeqstackPush(&stack, 'o');
	SeqstackPush(&stack, 'i');
	SeqstackPush(&stack, 'c');
	SeqstackPush(&stack, 'g');
	SeqstackPrint(&stack, "入栈");
}
Testmin()
{
	TEST;
	Seqstack stack;
	SeqstackInit(&stack);
	SeqstackPush(&stack, 'd');
	SeqstackPush(&stack, 'f');
	SeqstackPush(&stack, 'o');
	SeqstackPush(&stack, 'i');
	SeqstackPush(&stack, 'c');
	SeqstackPush(&stack, 'g');
	SeqstackPrint(&stack, "入栈");
	StackType* min = Seqstackmin(&stack);
	printf("min expected c,actual %c\n",*min);

}
TestPop()
{
	TEST;
	Seqstack stack;
	SeqstackInit(&stack);
	SeqstackPush(&stack, 'd');
	SeqstackPush(&stack, 'a');
	SeqstackPush(&stack, 'b');
	SeqstackPush(&stack, 'c');
	
	SeqstackPrint(&stack, "入栈");
	StackType* min = Seqstackmin(&stack);
	printf("min expected a,actual %c\n", *min);
	SeqstackPop(&stack);
	SeqstackPop(&stack);
	SeqstackPrint(&stack, "出栈");
	 min = Seqstackmin(&stack);
	printf("min expected a,actual %c\n", *min);
}
int main()
{
	TestPush();
	Testmin();
	TestPop();
	return 0;
}