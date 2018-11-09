#include"bloom_filter.h"
size_t BKDRHash(const char* str)
{
	assert(str);
	size_t hash = 0;
	while (*str++)
	{
		hash = hash * 131 + *str;
	}
	return hash;
}

 
size_t SDBMHash(const char *str)
{
	assert(str);
	size_t hash = 0;
	while (*str++)
	{
		hash = hash * 65599 + *str;
	}
	return hash;
}
void BloomFilterInit(BloomFilter* bf)
{
	if (bf == NULL)
	{
		return;
	}
	BitmapInit(&(bf->bitmap), BitmapMaxSize);
	bf->hash_func[0] = SDBMHash;
	bf->hash_func[1] = BKDRHash;
	return;
}
void BloomFilterDestroy(BloomFilter* bf)
{
	if (bf == NULL)
	{
		return;
	}
	bf->hash_func[0] = NULL;
	bf->hash_func[1] = NULL;
	BitmapDestroy(&bf->bitmap);
	return;
}
void BloomFilterInsert(BloomFilter* bf, const char* str)
{
	if (bf == NULL || str == NULL)
	{
		return;
	}
	
	size_t i = 0;
	for (; i < HashFuncMaxSize; ++i)
	{
		uint64_t hash = bf->hash_func[i](str) % HashFuncMaxSize;
		BitmapSet(&bf->bitmap, hash);
	}
	return;
}
int BloomFilterIsExist(BloomFilter* bf, const char* str)
{
	if (bf == NULL )
	{
		return -1;
	}
	assert(str);
	size_t i = 0;
	for (; i < HashFuncMaxSize; ++i)
	{
		uint64_t hash = bf->hash_func[i](str) % BitmapMaxSize;
		int ret =BitmapTest(&(bf->bitmap), hash);
		if (ret == 1)
		{
			return 1;
		}
	}
	return 0;
}
void TestBloom()
{
	
	BloomFilter bloom;
	BloomFilterInit(&bloom);
	BloomFilterInsert(&bloom, "helloworld");
	BloomFilterInsert(&bloom, "hello");
	BloomFilterInsert(&bloom, "world");
	int ret = BloomFilterIsExist(&bloom, "hello");
	printf("ret expected 1,actual %d\n", ret);
	ret = BloomFilterIsExist(&bloom, "fack");
	printf("ret expected 0,actual %d\n", ret);
	BloomFilterDestroy(&bloom);
}
int main()
{
	TestBloom();
	printf("\n");
	return 0;
}