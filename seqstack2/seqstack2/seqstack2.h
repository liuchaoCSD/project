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