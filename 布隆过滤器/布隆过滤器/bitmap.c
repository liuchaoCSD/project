#include"bitmap.h"
void BitmapInit(Bitmap* bt, uint64_t capacity)
{
	if (bt == NULL)
	{
		return;
	}
	bt->capacity = capacity;
	uint64_t size = capacity / (sizeof(bt->data[0]) * 8) + 1;
	bt->data = (BitmapType*)malloc(sizeof(BitmapType)*size);
	memset(bt->data, 0, sizeof(BitmapType)*size);
	return;
}
void BitmapDestroy(Bitmap* bt)
{
	if (bt == NULL)
	{
		return;
	}
	bt->capacity = 0;
	free(bt->data);
	return;
}
void Getoffset(uint64_t index, uint64_t* n, uint64_t* offset)
{
	*n = index / (sizeof(BitmapType)* 8);
	*offset = index % (sizeof(BitmapType)* 8);
	return;
}
int BitmapTest(Bitmap* bt, uint64_t index)
{
	if (bt == NULL || index >= bt->capacity)
	{
		return 0;
	}
	uint64_t n, offset;
	Getoffset(index, &n, &offset);
	uint64_t ret = bt->data[n] & (0x1ul << offset);
	return ret> 0 ? 1 : 0;
}
void BitmapSet(Bitmap* bt, uint64_t index)
{

	if (bt == NULL || index >= bt->capacity)
	{
		return;
	}
	uint64_t n, offset;
	Getoffset(index, &n, &offset);
	bt->data[n] = (0x1ul << offset);
	return;
}
void BitmapUnSet(Bitmap* bt, uint64_t index)
{
	if (bt == NULL || index >= bt->capacity)
	{
		return;
	}
	uint64_t n, offset;
	Getoffset(index, &n, &offset);
	bt->data[n] &= ~(0x1ul << offset);
	return;
}
void BitmapFill(Bitmap* bt, uint64_t capacity)
{
	if (bt == NULL)
	{
		return;
	}
	bt->capacity = capacity;
	uint64_t size = capacity / (sizeof(BitmapType)* 8) + 1;
	memset(bt->data, 0xff, sizeof(BitmapType)*size);
	return;
}
void BitmapClear(Bitmap* bt, uint64_t capacity)
{
	if (bt == NULL)
	{
		return;
	}
	bt->capacity = capacity;
	uint64_t size = capacity / (sizeof(BitmapType)* 8) + 1;
	memset(bt->data, 0x0, sizeof(BitmapType)*size);
	return;
}