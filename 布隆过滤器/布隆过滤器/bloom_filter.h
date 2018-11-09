#pragma once 
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"bitmap.h"
#define HashFuncMaxSize 2
#define BitmapMaxSize 1024 

typedef uint64_t (*HashFunc)(const char*);
typedef struct BloomFilter {
	Bitmap bitmap;
	HashFunc hash_func[HashFuncMaxSize];
} BloomFilter;
void BloomFilterInit(BloomFilter* bf);
void BloomFilterInsert(BloomFilter* bf, const char* str);
int BloomFilterIsExist(BloomFilter* bf, const char* str);
void BloomFilterDestroy(BloomFilter* bf);

// 按照当前的设计, 是不允许删除的. 
