#pragma once
/*
*线性表的所有的过程函数
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
          int MaxSize;   //最大容量
          int Length;//当前长度
}SeqList;


void InitList(SeqList* L);//顺序表的初始化
void Destory(SeqList* L);//顺序表的销毁
int IncreaseSize(SeqList* L, int len);//顺序表的动态增长
int LocateElem(SeqList L, ElemType e);//顺序表的按值查找
int Length(SeqList L);//求表长
void PrintList(SeqList L);//输出全表
int Empty(SeqList L);//表是否为空
void Reverse(SeqList* L);//线性表的逆转
void Merge(SeqList* L, SeqList* l1, SeqList* l2);//两个有序的线性表的合并
ElemType GetElem(SeqList L, int i);//顺序表的按位置号查找
void ClearList(SeqList* L);//清除顺序表

/*插入系列*/
void push_back(SeqList* L, ElemType item);//顺序表的尾插法
void push_front(SeqList* L, ElemType item);//顺序表的头插法
int ListInsert(SeqList* L, int  i, ElemType e);//顺序表的任意位置插入

/*删除系列*/
void pop_back(SeqList* L);//顺序表的尾部删除法
void pop_front(SeqList* L);//顺序表的头部删除法
int ListDeleteByPos(SeqList* L, int pos, ElemType* e);//顺序表的按照位序删除
int ListDeleteByNumber(SeqList* L, int num, ElemType* e);//顺序表的按照数值删除

/*排序类操作算法集合*/
void HeapSort(SeqList* L);//线性表的堆排序操作
void QuickSort(SeqList* L, int left, int right);//线性表的快速排序操作