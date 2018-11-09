#include"hash_func.h"
HashElem* CreateElem(keyType key, ValType value)
{
	HashElem* new_node = (HashElem*)malloc(sizeof(HashElem));
	new_node->key = key;
	new_node->value = value;
	new_node->next == NULL;
	return new_node;
}
void DestroyElem(HashTable* ht)
{
	free(ht);
	return;
}
void HashInit(HashTable* ht, HashFunc hash_func)
{

	ht->size = 0;
	ht->func = hash_func;
	size_t i = 0;
	for (; i < HashMaxSize; i++)
	{
		ht->data[i] = NULL;
	}
	return;
}

void HashPrint(HashTable* ht, const char *msg)
{
	printf("[%s]\n", msg);
	int  i = 0;
	for (; i < HashMaxSize; ++i){
		if (ht->data[i] == NULL)
		{
			continue;
		}
		printf("i=%lu\n", i);
		HashElem* cur = ht->data[i];
		for (; cur != NULL; cur = cur->next)
		{
			printf("[%d:%d]\n", cur->key, cur->value);
		}
		printf("\n");
	}
}
void HashInsert(HashTable* ht, keyType key, ValType value)
{
	if (ht == NULL)
	{
		return;
	}
	size_t offset = ht->func(key);

	int ret = HashBacketFind(ht->data[offset], key);
	if (ret == 1)
	{
		return;
	}
	HashElem* new_node = CreateElem(key, value);
	new_node->next = ht->data[offset];
	ht->data[offset] = new_node;
	++ht->size;
	return;
}
int HashBacketFind(HashElem* ht, keyType to_find)
{
	HashElem* cur = ht;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->key == to_find)
		{
			break;
		}
	}
}
int HashBacketFindEx(HashElem * head, keyType to_find, HashElem**pre_order, HashElem** cur_order)
{
	HashElem* cur = head;
	HashElem* pre = NULL;
	for (; cur != NULL; pre = cur, cur = cur->next)
	{
		if (cur->key == to_find)
		{
			break;
		}
	}
	if (cur == NULL)
	{
		return 0;
	}
	*pre_order = pre;
	*cur_order = cur;
	return 1;
}
void HashDestroy(HashTable *ht)
{
	if (ht == NULL)
	{
		return;
	}

	size_t i = 0;
	for (; i < HashMaxSize; i++)
	{
		ht->data[i] = NULL;
	}
	ht->size = 0;
	ht->func = NULL;

}
int  HashFind(HashTable* ht, keyType key, ValType* value)
{
	if (ht == NULL || value == NULL)
	{
		return 0;
	}
	size_t offset = func(key);
	HashElem* ret = HashBacketFind(ht->data[offset], key);
	if (ret == NULL)
	{
		return 0;
	}
	*value = ret->value;
	return 1;
}
void HashRemove(HashTable* ht, keyType key)
{
	if (ht == NULL)
	{
		return NULL;
	}
	if (ht->size == 0)
	{
		return;
	}
	size_t offset = ht->func(key);
	HashElem* pre = NULL;
	HashElem* cur = NULL;
	int ret = HashBacketFindEx(ht->data[offset], key, &pre, &cur);
	if (ret == 0)
	{
		return;
	}
	if (pre == NULL)
	{
		ht->data[offset] = cur->next;
	}
	//	pre->next = cur->next;
	DestroyElem(cur);
	--ht->size;
}