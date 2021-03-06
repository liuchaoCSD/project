#pragma once
#include<stdio.h>
#include<stdlib.h>
#define DEFAULT 4
typedef char StackType;
typedef struct Seqstack{
	StackType* data;
	int  size;
	int capacity;
}Seqstack;
void SeqstackInit(Seqstack* stack);
void SeqstackPush(Seqstack* stack, Seqstack data);
void SeqstackPop(Seqstack* stack);
void QueueInit(Seqstack* input, Seqstack* output);
void QueuePush(Seqstack*input, Seqstack* output, StackType data);
void QueuePop(Seqstack*input, Seqstack* output);