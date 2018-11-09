#pragma once
//////////////////////////////////////////////////////////////////
#include<iostream>
#include<stdarg.h>
#include<string>

using namespace std;
//#define __DEBUG__
static string GetFileName(const string& path)
{
	char ch = '/';
#ifdef _WIN32
	ch = '\\';
#endif
	size_t pos = path.rfind(ch);
	if (pos == string::npos)
		return path;
	else
		return path.substr(pos + 1);
}
//���ڵ���׷�ݵ�trace log
inline static void __trace_debug(const char* function,
	const char* filename, int line, char* format, ...)
{
#ifdef __DEBUG__
	//������ú�������Ϣ
	fprintf(stdout, "��%s:%d��%s", GetFileName(filename).c_str(), line, function);
	//����û����trace��Ϣ
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
#endif
}
#define __TRACE_LOG(...) \
	__trace_debug(__FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);

/////////////////////////////////////////////////////////////////

typedef void(*HANDLE_FUNC)();

template <int inst>  // Ԥ������ instance
class __MallocAllocTemplate
{
	static HANDLE_FUNC __malloc_alloc_oom_handler;

	static void* oom_malloc(size_t n)
	{
		while (1)
		{
			if (__malloc_alloc_oom_handler == 0)
			{
				throw bad_alloc();
			}
			else
			{
				__malloc_alloc_oom_handler();
				void* ret = malloc(n);
				if (ret)
					return ret;
			}
		}
	}

public:

	static HANDLE_FUNC SetMallocHandler(HANDLE_FUNC f)
	{
		HANDLE_FUNC old = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;

		return old;
	}

	static void* Allocate(size_t n)
	{
		void* result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);
		return result;
	}

	static void Deallocate(void *p, size_t /* n */)
	{
		free(p);
	}
};

template<int inst>
HANDLE_FUNC __MallocAllocTemplate<inst>::__malloc_alloc_oom_handler = 0;

void FreeHandle()
{
	cout << "�����ͷ��ڴ�" << endl;
}

void TestMallocAlloc()
{
	__MallocAllocTemplate<0>::SetMallocHandler(FreeHandle);

	__MallocAllocTemplate<0>::Allocate(0x7fffffff);
}

template <bool threads, int inst>
class __DefaultAllocTemplate
{
	enum { __ALIGN = 8 };
	enum { __MAX_BYTES = 128 };
	enum { __NFREELISTS = __MAX_BYTES / __ALIGN };

	union Obj {
		union Obj* _freeListLink;
	};

	// ��������
	static Obj * _freeList[__NFREELISTS];

	// �ڴ��
	static char* _startFree;
	static char* _endFree;
	static size_t _heapSize;

	static  size_t FREELIST_INDEX(size_t bytes)
	{
		return (((bytes)+__ALIGN - 1) / __ALIGN - 1);
	}

	static size_t ROUND_UP(size_t bytes)
	{
		return (((bytes)+__ALIGN - 1) & ~(__ALIGN - 1));
	}

public:
	static char* ChunkAlloc(size_t n, size_t& nobjs)
	{
		size_t totalbytes = n*nobjs;
		size_t leftbytes = _endFree - _startFree;
		if (leftbytes >= totalbytes)
		{
			__TRACE_LOG("�ڴ�����㹻20�������С\n");

			char* ret = _startFree;
			_startFree += totalbytes;
			return ret;
		}
		else if (leftbytes >= n)
		{
			nobjs = leftbytes / n;
			__TRACE_LOG("�ڴ��ֻ��%u������\n", nobjs);

			totalbytes = nobjs*n;
			char* ret = _startFree;
			_startFree += totalbytes;
			return ret;
		}
		else
		{
			__TRACE_LOG("�ڴ��һ�����󶼲���\n");

			// �����ڴ��ʣ���С���ڴ�
			if (leftbytes > 0)
			{
				size_t index = FREELIST_INDEX(leftbytes);
				((Obj*)_startFree)->_freeListLink = _freeList[index];
				_freeList[index] = (Obj*)_startFree;
			}

			size_t bytesToGet = nobjs*n * 2 + ROUND_UP(_heapSize >> 4);
			__TRACE_LOG("��ϵͳ����%u bytes���ڴ��\n", bytesToGet);

			_startFree = (char*)malloc(bytesToGet);
			if (_startFree == NULL)
			{
				// ���������������ȡ����
				for (size_t i = n; i < __MAX_BYTES; i += __ALIGN)
				{
					size_t index = FREELIST_INDEX(i);
					if (_freeList[index])
					{
						Obj* obj = _freeList[index];
						_freeList[index] = obj->_freeListLink;
						_startFree = (char*)obj;
						_endFree = _startFree + i;

						return ChunkAlloc(n, nobjs);
					}
				}

				_startFree = (char*)__MallocAllocTemplate<0>::Allocate(bytesToGet);
			}

			_endFree = _startFree + bytesToGet;
			_heapSize += bytesToGet;
			return ChunkAlloc(n, nobjs);
		}
	}

	static void* Refill(size_t n)
	{
		size_t nobjs = 20;
		char* chunk = ChunkAlloc(n, nobjs);
		if (nobjs == 1)
			return chunk;

		__TRACE_LOG("��ϵͳ���뵽%u���ڴ���󣬷���һ����ʣ�µĹ�����\n", nobjs);


		Obj* cur = (Obj*)(chunk + n);
		size_t index = FREELIST_INDEX(n);
		_freeList[index] = cur;

		for (size_t i = 0; i < nobjs - 2; ++i)
		{
			Obj* next = (Obj*)((char*)cur + n);
			cur->_freeListLink = next;

			cur = next;
		}

		cur->_freeListLink = NULL;

		return chunk;
	}

	static void* Allocate(size_t n)
	{
		// ����128.����һ���ռ�������
		if (n > 128)
		{
			__TRACE_LOG("��һ���ռ����������룺%u\n", n);
			return __MallocAllocTemplate<0>::Allocate(n);
		}

		__TRACE_LOG("������ռ����������룺%u\n", n);

		size_t index = FREELIST_INDEX(n);
		if (_freeList[index] == NULL)
		{
			return Refill(ROUND_UP(n));
		}
		else
		{
			__TRACE_LOG("��freelist[%u]λ��ȡһ���ڴ��\n", index);

			Obj* obj = _freeList[index];
			_freeList[index] = obj->_freeListLink;
			return obj;
		}
	}

	static void Deallocate(void* ptr, size_t n)
	{
		if (n > __MAX_BYTES)
		{
			__MallocAllocTemplate<0>::Deallocate(ptr, n);
		}
		else
		{
			size_t index = FREELIST_INDEX(n);
			__TRACE_LOG("��%p�ҵ�freeList[%u]\n", ptr, index);

			Obj* obj = (Obj*)ptr;
			obj->_freeListLink = _freeList[index];
			_freeList[index] = obj;
		}
	}

};

template <bool threads, int inst>
typename __DefaultAllocTemplate<threads, inst>::Obj*
__DefaultAllocTemplate<threads, inst>::_freeList[__NFREELISTS] = { NULL };

// �ڴ��
template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_startFree = NULL;

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_endFree = NULL;

template <bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::_heapSize = 0;

void TestDefaultAlloc()
{
	for (size_t i = 0; i < 41; ++i)
	{
		__DefaultAllocTemplate<false, 0>::Allocate(5);
	}
}

#ifdef __USE_MALLOC
typedef __MallocAllocTemplate<0> alloc;
#else
typedef __DefaultAllocTemplate<false, 0> alloc;
#endif // __USE_MALLOC


template<class T, class Alloc>
class SimpleAlloc {
public:
	static T* Allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::Allocate(n * sizeof (T));
	}
	static T* Allocate(void)
	{
		return (T*)Alloc::Allocate(sizeof (T));
	}
	static void Deallocate(T *p, size_t n)
	{
		if (0 != n) Alloc::Deallocate(p, n * sizeof (T));
	}
	static void Deallocate(T *p)
	{
		Alloc::Deallocate(p, sizeof (T));
	}
};