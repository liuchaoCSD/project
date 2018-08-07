#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 10
typedef char DataType;
typedef struct Sharestack{
	DataType data[MAX_SIZE];
	int top1;
	int top2;
}Sharestack;
void SharestackInit(Sharestack* stack);
void SharestackPush(Sharestack* stack, int stateNum, DataType data);
void SharestackPop(Sharestack* stack, int stateNum);
void SharestackPrintf(Sharestack* stack, const char* msg);