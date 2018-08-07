#include"seqstack.h"
#define TEST printf("==========%s=========\n",__FUNCTION__);
void QueueInit(Queue *q)
{
	if (q == NULL)
	{
		return;
	}
	q->data = (QueueType*)malloc(sizeof(QueueType)*DEFAULT);
	q->size = 0;
	q->capacity = DEFAULT;
}
void QueuePrint(Queue* q, const char *msg)
{
	printf("==============%s==========\n", msg);
	if (q == NULL)
	{
		return;
	}
	
	for (int i = q->size-1; i>=0; i--)
	{
		printf("%c\t", q->data[i]);
	}
	printf("\n");
}



void QueuePush(Queue *q, QueueType data)
{
	if (q == NULL)
	{
		return;
	}
	if (q->size == q->capacity)
	{
		QueueType* ptr = (QueueType*)realloc(q->data, sizeof(QueueType)* q->capacity * 2 + 1);
		q->data = ptr;
	}
	q->data[q->size] = data;
	q->size++;
}
void QueuePop(Queue *q)
{
	if (q == NULL)
	{
		return;
	}
	if (q->size == 0)
	{
		return;
	}
	int i = 0;
	for (; i < q->size ; ++i)
	{
		q->data[i] = q->data[i+ 1];
	}
	q->size--;
}
void SeqstackInit(Queue* q1, Queue*q2)
{
	if (q1 == NULL || q2 == NULL)
	{
		return;
	}
	QueueInit(q1);
	QueueInit(q2);
}
void SeqstackPush(Queue* q1, Queue* q2, QueueType data)
{
	if (q1 == NULL || q2 == NULL)	{
		return;
	}
	if (q2->size != 0)
	{
		QueuePush(q2, data);
	}
	else {
		QueuePush(q1, data);
	}

}
void SeqstackPop(Queue* q1, Queue* q2)
{
	if (q1 == NULL || q2 == NULL)	{
		return;
	}
	if (q1->size != 0)
	{
		int i = 0;
		int size = q1->size;
		while (i < size - 1)
		{
			QueueType to_push = q1->data[0];
			QueuePop(q1);
			QueuePush(q2, to_push);
			i++;
		}
		QueuePop(q1);
	}
	else 
	{
		int i = 0;
		int size = q2->size;
		while (i < size - 1)
		{
			QueueType to_push = q2->data[0];
			QueuePop(q2);
			QueuePush(q1, to_push);
			i++;
		}
		QueuePop(q2);
	}
}
void SeqstackPrint(Queue* q1, Queue* q2, const char* msg)
{
	if (q1 == NULL || q2 == NULL)
	{
		return;
	}
	if (q1->size != 0)
	{
		QueuePrint(q1, msg);
	}
	else
	{
		QueuePrint(q2, msg);
	}
}
void Test()
{
	TEST;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 'a');
	QueuePush(&q, 'b');
	QueuePush(&q, 'c');
	QueuePush(&q, 'd');
	QueuePrint(&q, "入队列四个元素");
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q, "出队列两个元素");
}

Test1()
{
	Queue q1,q2;
	SeqstackInit(&q1,&q2);
	SeqstackPush(&q1, &q2, 'a');
	SeqstackPush(&q1, &q2, 'b');
	SeqstackPush(&q1, &q2, 'c');
	SeqstackPush(&q1, &q2, 'd');
	SeqstackPrint(&q1, &q2, "入栈四个元素");
	SeqstackPop(&q1,&q2);
	SeqstackPop(&q1, &q2);
	SeqstackPrint(&q1, &q2, "出栈两个元素");
}
int main()
{
	Test();
	Test1();
	return 0;
}