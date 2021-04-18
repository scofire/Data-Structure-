#include "dynamicArray.h"




//初始化数组
struct dynamicArray* init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return;
	}

	struct dynamicArray* array = malloc(sizeof(struct dynamicArray));
	if (array == NULL)
	{
		return NULL;
	}
	array->pAddr=malloc(sizeof(void*)*capacity);
	array->m_capacity=capacity;
	array->m_size=0;

	return;
}


void insert_DynamicArray(struct dynamicArray* array, int pos, void* data)
{
	if (array == NULL)
	{
		return;
	}

	//无效位置，尾插
	if (pos<0 || pos>array->m_size)
	{
		pos=array->m_size;
	}

	//容量已满，需扩容
	if (array->m_size == array->m_capacity)
	{
		int newCapacity=array->m_capacity*2;
		void ** newspace=malloc(sizeof(void*)*newCapacity);
		memcpy(newCapacity,array->pAddr,sizeof(void*)*array->m_capacity);
		free(array->pAddr);
		array->pAddr=newspace;
		array->m_capacity=newCapacity;
	}

	//插入新元素
	//移动元素
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i+1]=array->pAddr[i];
	}
	array->pAddr[pos]=data;
	array->m_size++;

}


//遍历数组
void foreach_DynamicArray(struct dynamicArray* array, void(*myPrint)(void*))
{
	if (array == NULL)
	{
		return;
	}
	if (myPrint == NULL)
	{
		return;
	}
	for (int i = 0; i < array->m_size; i++)
	{
		myPrint(array->pAddr[i]);
	}
}

void removeByPos_DynamicArray(struct dynamicArray* array, int pos)
{
	if (NULL == array)
	{
		return;
	}

	for (int i = pos; i < array->m_size; i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}

	array->m_size--;
}

void removeByValue_DynamicArray(struct dynamicArray* array, void* data, int(*myCompare)(void*, void*))
{
	//找到值相等那个位置
	if (array == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	for (int i = 0; i < array->m_size; i++)
	{
		if (myCompare(array->pAddr[i], data))
		{
			removeByPos_DynamicArray(array,i);
			break;
		}
	}
}

void destroy_DynamicArray(struct dynamicArray* array) 
{
	if (array == NULL)
	{
		return;
	}
	if (array->pAddr != NULL)
	{
		free(array->pAddr);
		array->pAddr=NULL;
	}

	free(array);
	array=NULL;
}

