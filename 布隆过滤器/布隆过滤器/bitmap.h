#pragma once 
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
typedef int BitmapType;
typedef struct Bitmap{
	uint64_t* data;
	uint64_t capacity;
}Bitmap;
void BitmapInit(Bitmap* bt, uint64_t capacity);
void BitmapDestroy(Bitmap* bt);
int BitmapTest(Bitmap* bt, uint64_t capacity);
void BitmapSet(Bitmap* bt, uint64_t index);
void BitmapUnSet(Bitmap* bt, uint64_t index);
void BitmapFill(Bitmap* bt, uint64_t capacity);
void BitmapClear(Bitmap* bt, uint64_t capacity);
