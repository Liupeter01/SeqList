#pragma once
/*
*���Ա�����еĹ��̺���
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

#define USING_INT

#ifdef USING_INT
#define ElemType int
#endif

typedef struct SeqList
{
          ElemType* data;
          int MaxSize;   //�������
          int Length;//��ǰ����
}SeqList;


void InitList(SeqList* L);//˳���ĳ�ʼ��
void Destory(SeqList* L);//˳��������
int IncreaseSize(SeqList* L, int len);//˳���Ķ�̬����
int LocateElem(SeqList L, ElemType e);//˳���İ�ֵ����
int Length(SeqList L);//���
void PrintList(SeqList L);//���ȫ��
int Empty(SeqList L);//���Ƿ�Ϊ��
void Reverse(SeqList* L);//���Ա����ת
void Merge(SeqList* L, SeqList* l1, SeqList* l2);//������������Ա�ĺϲ�
ElemType GetElem(SeqList L, int i);//˳���İ�λ�úŲ���
void ClearList(SeqList* L);//���˳���

/*����ϵ��*/
void push_back(SeqList* L, ElemType item);//˳����β�巨
void push_front(SeqList* L, ElemType item);//˳����ͷ�巨
int ListInsert(SeqList* L, int  i, ElemType e);//˳��������λ�ò���

/*ɾ��ϵ��*/
void pop_back(SeqList* L);//˳����β��ɾ����
void pop_front(SeqList* L);//˳����ͷ��ɾ����
int ListDeleteByPos(SeqList* L, int pos, ElemType* e);//˳���İ���λ��ɾ��
int ListDeleteByNumber(SeqList* L, int num, ElemType* e);//˳���İ�����ֵɾ��

/*����������㷨����*/
void HeapSort(SeqList* L);//���Ա�Ķ��������
void QuickSort(SeqList* L, int left, int right);//���Ա�Ŀ����������