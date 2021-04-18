#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct dynamicArray
{

	void ** pAddr;    //ά����ʵ���������������ָ��
	int m_capacity;   //��������
	int m_size;       //�����С
};


//��ʼ������
struct dynamicArray * init_DynamciArray(int capacity);

//��������
void insert_DynamicArray(struct dynamicArray *array,int pos,void * data);

//��������
void foreach_DynamicArray(struct dynamicArray *array,void(*myPrint)(void*));

//��λ��ɾ������
void removeByPos_DynamicArray(struct dynamicArray *array ,int pos);

//��ֵɾ������
void removeByValue_DynamicArray(struct dynamicArray * array,void *data,int(*mCompare)(void *,void *));

//��������
void destroy_DynamicArray(struct dynamicArray *array);

