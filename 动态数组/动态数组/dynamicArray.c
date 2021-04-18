#include "dynamicArray.h"




//��ʼ������
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

	//��Чλ�ã�β��
	if (pos<0 || pos>array->m_size)
	{
		pos=array->m_size;
	}

	//����������������
	if (array->m_size == array->m_capacity)
	{
		int newCapacity=array->m_capacity*2;
		void ** newspace=malloc(sizeof(void*)*newCapacity);
		memcpy(newCapacity,array->pAddr,sizeof(void*)*array->m_capacity);
		free(array->pAddr);
		array->pAddr=newspace;
		array->m_capacity=newCapacity;
	}

	//������Ԫ��
	//�ƶ�Ԫ��
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i+1]=array->pAddr[i];
	}
	array->pAddr[pos]=data;
	array->m_size++;

}


//��������
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
	//�ҵ�ֵ����Ǹ�λ��
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

