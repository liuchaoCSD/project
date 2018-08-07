#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEFAULT 4
typedef char QueueType;
typedef struct Queue{
	QueueType* data;
	int size;
	int capacity;
}Queue;
void QueueInit(Queue *q);
void QueuePush(Queue *q, QueueType data);
void QueuePop(Queue *q);
void SeqstackInit(Queue* q1, Queue*q2);
void SeqstackPush(Queue* q1, Queue* q2, QueueType data);
void SeqstackPop(Queue* q1, Queue* q2);

