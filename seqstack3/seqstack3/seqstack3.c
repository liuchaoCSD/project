#include"seqstack3.h"
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
	printf("队尾\n");
	for (int i = stack->size - 1; i >= 0; --i)
	{
		printf("[%c]\t", stack->data[i]);
	}
	printf("\n");
	printf("队首\n");
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
		return ;
	}
	if (stack->size == 0)
	{
		return ;
	}
	--stack->size;
}
void QueueInit(Seqstack* input, Seqstack* output)
{
	if (input == NULL || output == NULL)
	{
		return;
	}
	SeqstackInit(input);
	SeqstackInit(output);
}
void QueuePush(Seqstack*input, Seqstack* output,StackType data)
{
	if (input == NULL || output == NULL)
	{
		return;
	}
	SeqstackPush(input, data);
}
void QueuePop(Seqstack*input, Seqstack* output)
{
	if (input == NULL || output == NULL)
	{
		return;
	}
	if (input->size == 0)
	{
		return;
	}
	else
	{
		int i = input->size;
		while (i > 0)
		{
			StackType to_push = input->data[i - 1];
			SeqstackPop(input);
			SeqstackPush(output, to_push);
			i--;
		}
	}
SeqstackPop(output);
if (output->size == 0)
{
	return;
}
else
{
	int j = output->size;
	while (j > 0)
	{
		StackType to_back = output->data[j - 1];
		SeqstackPop(output);
		SeqstackPush(input, to_back);
		j--;
	}
}
}
QueuePrint(Seqstack* input, Seqstack* output, const char* msg)
{
	SeqstackPrint(input, msg);
}
int main()
{
	Seqstack input;
	Seqstack output;
	QueueInit(&input, &output);
	QueuePush(&input, &output, 'a');
	QueuePush(&input, &output, 'b');
	QueuePush(&input, &output, 'c');
	QueuePush(&input, &output, 'd');
	QueuePrint(&input, &output, "入队列四个元素");
	QueuePop(&input, &output);
	QueuePop(&input, &output);
	QueuePrint(&input, &output, "出队列两个元素");
	return 0;
}