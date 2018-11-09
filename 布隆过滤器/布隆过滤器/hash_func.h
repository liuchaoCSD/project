#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TEST  printf("\n=========%s=========\n",__FUNCTION__);
#define HashMaxSize 1024
typedef int keyType;
typedef int ValType;
typedef size_t(*HashFunc)(keyType key);
typedef enum Stat {
	Empty,
	Deleted,
	Valid,
}Stat;

typedef struct HashElem
{
	keyType key;
	ValType value;
	struct HashElem* next;
	Stat stat;
}HashElem;
int func(keyType key)
{
	return key% HashMaxSize;

}
typedef struct HashTable{
	HashElem *data[HashMaxSize];
	size_t size;
	HashFunc func;
}HashTable;
void HashInit(HashTable* ht, HashFunc hash_func);
void HashInsert(HashTable* ht, keyType key, ValType value);
int  HashFind(HashTable* ht, keyType key, ValType* value);
void HashRemove(HashTable* ht, keyType key);
void HashDestroy(HashTable *ht);
