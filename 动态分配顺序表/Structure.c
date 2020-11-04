#include"Structure.h"

/*顺序表的初始化*/
void InitList(SeqList* L)
{
          L->MaxSize = 0xFFFF;
          L->data = (ElemType*)calloc(L->MaxSize, sizeof(ElemType));
          memset(L->data, 0, sizeof(ElemType) * L->MaxSize);
          assert(L->data != NULL);                //静态断言用来检测
          L->Length = 0;
}

/*顺序表的销毁*/
void Destory(SeqList* L)
{
          free(L->data);                //摧毁
          L->data = NULL;
          L->Length = 0;
          L->MaxSize = 0;
}

//清除顺序表
void ClearList(SeqList* L)
{
          memset(L->data, 0, sizeof(ElemType) * L->MaxSize);
          L->Length = 0;
}

/*顺序表的动态增长*/
int IncreaseSize(SeqList* L, int len)
{
          L->data = (ElemType*)realloc(L->data, sizeof(ElemType) * (L->MaxSize + len));
          assert(L->data != NULL);
          if (L->data == NULL)
          {
                    printf("程序增加空间失败，内存不足\n");
                    return 0;
          }
          else
          {
                    L->MaxSize += len;
                    return 1;
          }
}

/*顺序表的头插法*/
void push_front(SeqList* L, ElemType item)
{
          //空间已满1，但是可以自动的扩展空间则继续操作1
          //若空间已满1，但是自动扩展空间失败0，内存不足则返回
          if (L->Length + 1 == L->MaxSize && !IncreaseSize(L,1))       //可以自动的扩展空间
          {
                    printf("表已满，不可以插入数据\n");
                    return;
          }
          for (int i = L->Length; i > 0; --i)     //移动
          {
                    L->data[i] = L->data[i - 1];
          }
          L->data[0] = item;            //头部插入
          L->Length++;
}

/*顺序表的尾插法*/
void push_back(SeqList* L, ElemType item)
{
          //空间已满1，但是可以自动的扩展空间则继续操作1
          //若空间已满1，但是自动扩展空间失败0，内存不足则返回
          if (L->Length + 1 == L->MaxSize && !IncreaseSize(L, 1))       
          {
                    printf("表已满，不可以插入数据\n");
                    return;
          }
          L->data[(L->Length)++] = item;
}

/*顺序表的插入*/
int ListInsert(SeqList* L, int  pos, ElemType e)
{
          if (pos<1 || pos > L->Length)           //判断i的范围是否有效
          {
                    printf("插入的数据的位置非法，不可以插入数据\n");
                    return 0;
          }
          else if (L->Length + 1 > L->MaxSize && !IncreaseSize(L, 1))
          {
                    //空间已满1，但是可以自动的扩展空间则继续操作1
                     //若空间已满1，但是自动扩展空间失败0，内存不足则返回
                    printf("数据不可以插入，数组已满\n");
                    return 0;
          }
          for (int j = L->Length; j >= pos; --j)
          {
                    L->data[j] = L->data[j - 1];
          }
          L->data[pos - 1] = e;   //位置4对应于下标3
          L->Length++;
          return 1;
}

/*顺序表的尾部删除法*/
void pop_back(SeqList* L)
{
          if (L->Length == 0)
          {
                    printf("顺序表的大小为空，不可以删除\n");
                    return;
          }
          else
          {
                    /*
                    *当然也可以直接进行L->length--
                    *删除一个数据并不一定必须从物理内存中删除，从逻辑上删除也可以
                    */
                    L->data[L->Length - 1] = 0;             //删除初始化为0
                    L->Length--;
          }
}

/*顺序表的头部删除法*/
void pop_front(SeqList* L)
{
          if (L->Length == 0)
          {
                    printf("顺序表的大小为空，不可以删除\n");
                    return;
          }
          else
          {
                    for (int i = 1; i < L->Length; ++i)
                    {
                              L->data[i - 1] = L->data[i];
                    }
                    L->data[L->Length - 1] = 0;
                    L->Length--;
          }
}

/*顺序表的按照位序删除*/
int ListDeleteByPos(SeqList* L, int pos, ElemType* e)
{
          if (pos<1 || pos > L->Length)           //判断i的范围是否有效
          {
                    printf("删除数据的位置非法，不可以删除数据\n");
                    return 0;
          }
          else
          {
                    *e = L->data[pos - 1];  //取出删除的元素
                    for (int j = pos; j < L->Length; ++j)
                    {
                              L->data[j - 1] = L->data[j];
                    }
                    L->Length--;                  //元素的数量自减
                    return 1;
          }
}

/*顺序表的按照数值删除*/
int ListDeleteByNumber(SeqList* L, int num, ElemType* e)
{
          int pos = -1;
          while (L->data[++pos] != num && pos != L->Length);
          if (pos == -1)      //没有找到
          {
                    printf("数据的没有找到，不可以删除数据\n");
                    return -1;
          }
          else
          {
                    *e = L->data[pos];  //取出删除的元素
                    for (int j = pos; j < L->Length - 1 ; ++j)
                    {
                              L->data[j] = L->data[j + 1];
                    }
                    L->Length--;                  //元素的数量自减
                    return 1;
          }
}

/*顺序表的按值查找，并返回其位序*/
int LocateElem(SeqList L, ElemType e)
{
          int flag = 0;
          int pos = 0;
          for (int i = 0; i < L.Length; i++)
          {
                    if (L.data[i] == e)
                    {
                              flag = 1;
                              pos = i + 1;
                    }
          }
          return flag != 0 ? pos : -1;
}

/*顺序表的按位置号查找*/
ElemType GetElem(SeqList L, int i)
{
          if (i<1 || i > L.Length)           //判断i的范围是否有效
          {
                    printf("输入的位置错误\n");
                    return 0;
          }
          else
          {
                    return L.data[i - 1];
          }
}

/*求表长*/
int Length(SeqList L)
{
          return L.Length;
}

/*输出全表*/
void PrintList(SeqList L)
{
          for (int i = 0; i < L.Length; ++i)
          {
                    printf("%d   ", L.data[i]);
          }
          printf("\n");
}

/*表是否为空*/
int Empty(SeqList L)
{
          if (L.Length == 0)
          {
                    return 1;
          }
          else
          {
                    return 0;
          }
}

/*通用数据交换模组*/
void swap(ElemType* a1, ElemType* a2)
{
          ElemType temp = *a1;
          *a1 = *a2;
          *a2 = temp;
}

/*线性表的逆转*/
void Reverse(SeqList* L)
{
          if (L->Length == 0 || L->Length == 1)
          {
                    return;
          }
          else
          {
                    for (int i = 0; i < L->Length / 2; ++i)
                    {
                              swap(&L->data[i], &L->data[L->Length - i - 1]);
                    }
          }
}

//两个有序的线性表l1和l2合并为一个新的线性表
void Merge(SeqList* L, SeqList* l1, SeqList* l2)
{
          HeapSort(l1);       //将线性表l1有序化
          HeapSort(l2);       //将线性表l2有序化
          L->Length = l1->Length + l2->Length;
          L-> data = (ElemType*)malloc(sizeof(ElemType)*L->Length);      //扩展长度
          int i = 0, j = 0, pos = 0;              //i存储l1，j存储l2，pos存储L
          for (i, j,pos; i <= l1->Length - 1 &&  j <= l2->Length - 1; )
          {
                    if (l1->data[i] < l2->data[j])
                    {
                              L->data[pos++] = l1->data[i++];
                    }
                    else
                    {
                              L->data[pos++] = l2->data[j++];
                    }
          }
          while (i <= l1->Length - 1)
          {
                    L->data[pos++] = l1->data[i++];
          }
          while (j <= l2->Length - 1)
          {
                    L->data[pos++] = l2->data[j++];
          }
}

/*线性表的堆排序操作*/
void HeapSort(SeqList* L)
{
          for (int i = L->Length - 1 ; i >= 0; --i)
          {
                    for (int j = i - 1; j >= 0; j-=2)
                    {
                              int parent = j / 2;
                              if (L->data[j] > L->data[j + 1])
                              {
                                        if (L->data[j] > L->data[parent])
                                        {
                                                  swap(&L->data[j], &L->data[parent]);
                                        }
                              }
                              else
                              {
                                        if (L->data[j+1] > L->data[parent])
                                        {
                                                  swap(&L->data[j + 1], &L->data[parent]);
                                        }
                              }
                    }
                    swap(&L->data[0], &L->data[i]);
          }
}

/*线性表的快速排序操作*/
void QuickSort(SeqList* L,int left,int right)
{
          int i = left;
          int j = right;
          if (i < j)
          {
                    while (i < j)
                    {
                              while (L->data[left] >= L->data[i] && i <= right)
                              {
                                        ++i;
                              }
                              while (L->data[left] <= L->data[j] && j > left)
                              {
                                        --j;
                              }
                              if (i < j)
                              {
                                        swap(&L->data[i], &L->data[j]);
                              }
                    }
                    swap(&L->data[left], &L->data[j]);
                    QuickSort(L, left, j - 1);
                    QuickSort(L, j + 1, right);
          }
}