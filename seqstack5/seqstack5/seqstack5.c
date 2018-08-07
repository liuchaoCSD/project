#include"seqstack5.h"
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
  for (int i = stack->size - 1; i >= 0; --i)
	{
		printf("[%c]\t", stack->data[i]);
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
	stack->data[stack->size] = data;
	++stack->size;
}
void SeqstackPop(Seqstack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	--stack->size;
}
StackType* SeqstackTop(Seqstack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	if (stack->size == 0)
	{
		return;
	}
	return &stack->data[stack->size - 1];
}
int JudgeString(Seqstack* stack, char*to_push_msg, char* to_judge_msg)
{
	if (stack == NULL || to_push_msg == NULL || to_judge_msg == NULL)
	{
		return;
	}
	char* p_push = to_push_msg;
	char* p_judge = to_judge_msg;
	while (*p_push != 0)
	{
		if (*p_push != *p_judge)
		{
			SeqstackPush(stack, *p_push);
			p_push++;
		}
		else
		{
			p_push++;
			p_judge++;
		}
       }
	if (*p_judge != 0)
	{
		StackType* top = SeqstackTop(stack);
		while (top != 0 && *p_judge == *top)
		{
			SeqstackPop(stack);
			p_judge++;
			top = SeqstackTop(stack);
		}
		if (*p_judge == 0)
		{
			return 1;
		}
		return 0;
	}
	else {
		return 1;
	}
}

int main()
{
	Seqstack stack;
	
	SeqstackInit(&stack);
	SeqstackPush(&stack, 'a');
	SeqstackPush(&stack, 'b');
	SeqstackPush(&stack, 'c');
	SeqstackPush(&stack, 'd');
	SeqstackPrint(&stack, "入栈四个元素");
	SeqstackPop(&stack);
	SeqstackPop(&stack);
	SeqstackPrint(&stack, "出栈两个元素");
	printf("\n======测试出栈合法性======\n");
	int ret = JudgeString(&stack, "asdcs", "dcsab");
	if (ret == 1)
	{
		printf("[%s]to [%s] 合法\n", "asdcs", "dscab");
	}
	else {
		printf("[%s]to [%s] 不合法\n", "asdcs", "dscab");
	}
  return 0;
}