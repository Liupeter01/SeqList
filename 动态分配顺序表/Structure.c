#include"Structure.h"

/*˳���ĳ�ʼ��*/
void InitList(SeqList* L)
{
          L->MaxSize = 0xFFFF;
          L->data = (ElemType*)calloc(L->MaxSize, sizeof(ElemType));
          memset(L->data, 0, sizeof(ElemType) * L->MaxSize);
          assert(L->data != NULL);                //��̬�����������
          L->Length = 0;
}

/*˳��������*/
void Destory(SeqList* L)
{
          free(L->data);                //�ݻ�
          L->data = NULL;
          L->Length = 0;
          L->MaxSize = 0;
}

//���˳���
void ClearList(SeqList* L)
{
          memset(L->data, 0, sizeof(ElemType) * L->MaxSize);
          L->Length = 0;
}

/*˳���Ķ�̬����*/
int IncreaseSize(SeqList* L, int len)
{
          L->data = (ElemType*)realloc(L->data, sizeof(ElemType) * (L->MaxSize + len));
          assert(L->data != NULL);
          if (L->data == NULL)
          {
                    printf("�������ӿռ�ʧ�ܣ��ڴ治��\n");
                    return 0;
          }
          else
          {
                    L->MaxSize += len;
                    return 1;
          }
}

/*˳����ͷ�巨*/
void push_front(SeqList* L, ElemType item)
{
          //�ռ�����1�����ǿ����Զ�����չ�ռ����������1
          //���ռ�����1�������Զ���չ�ռ�ʧ��0���ڴ治���򷵻�
          if (L->Length + 1 == L->MaxSize && !IncreaseSize(L,1))       //�����Զ�����չ�ռ�
          {
                    printf("�������������Բ�������\n");
                    return;
          }
          for (int i = L->Length; i > 0; --i)     //�ƶ�
          {
                    L->data[i] = L->data[i - 1];
          }
          L->data[0] = item;            //ͷ������
          L->Length++;
}

/*˳����β�巨*/
void push_back(SeqList* L, ElemType item)
{
          //�ռ�����1�����ǿ����Զ�����չ�ռ����������1
          //���ռ�����1�������Զ���չ�ռ�ʧ��0���ڴ治���򷵻�
          if (L->Length + 1 == L->MaxSize && !IncreaseSize(L, 1))       
          {
                    printf("�������������Բ�������\n");
                    return;
          }
          L->data[(L->Length)++] = item;
}

/*˳���Ĳ���*/
int ListInsert(SeqList* L, int  pos, ElemType e)
{
          if (pos<1 || pos > L->Length)           //�ж�i�ķ�Χ�Ƿ���Ч
          {
                    printf("��������ݵ�λ�÷Ƿ��������Բ�������\n");
                    return 0;
          }
          else if (L->Length + 1 > L->MaxSize && !IncreaseSize(L, 1))
          {
                    //�ռ�����1�����ǿ����Զ�����չ�ռ����������1
                     //���ռ�����1�������Զ���չ�ռ�ʧ��0���ڴ治���򷵻�
                    printf("���ݲ����Բ��룬��������\n");
                    return 0;
          }
          for (int j = L->Length; j >= pos; --j)
          {
                    L->data[j] = L->data[j - 1];
          }
          L->data[pos - 1] = e;   //λ��4��Ӧ���±�3
          L->Length++;
          return 1;
}

/*˳����β��ɾ����*/
void pop_back(SeqList* L)
{
          if (L->Length == 0)
          {
                    printf("˳���Ĵ�СΪ�գ�������ɾ��\n");
                    return;
          }
          else
          {
                    /*
                    *��ȻҲ����ֱ�ӽ���L->length--
                    *ɾ��һ�����ݲ���һ������������ڴ���ɾ�������߼���ɾ��Ҳ����
                    */
                    L->data[L->Length - 1] = 0;             //ɾ����ʼ��Ϊ0
                    L->Length--;
          }
}

/*˳����ͷ��ɾ����*/
void pop_front(SeqList* L)
{
          if (L->Length == 0)
          {
                    printf("˳���Ĵ�СΪ�գ�������ɾ��\n");
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

/*˳���İ���λ��ɾ��*/
int ListDeleteByPos(SeqList* L, int pos, ElemType* e)
{
          if (pos<1 || pos > L->Length)           //�ж�i�ķ�Χ�Ƿ���Ч
          {
                    printf("ɾ�����ݵ�λ�÷Ƿ���������ɾ������\n");
                    return 0;
          }
          else
          {
                    *e = L->data[pos - 1];  //ȡ��ɾ����Ԫ��
                    for (int j = pos; j < L->Length; ++j)
                    {
                              L->data[j - 1] = L->data[j];
                    }
                    L->Length--;                  //Ԫ�ص������Լ�
                    return 1;
          }
}

/*˳���İ�����ֵɾ��*/
int ListDeleteByNumber(SeqList* L, int num, ElemType* e)
{
          int pos = -1;
          while (L->data[++pos] != num && pos != L->Length);
          if (pos == -1)      //û���ҵ�
          {
                    printf("���ݵ�û���ҵ���������ɾ������\n");
                    return -1;
          }
          else
          {
                    *e = L->data[pos];  //ȡ��ɾ����Ԫ��
                    for (int j = pos; j < L->Length - 1 ; ++j)
                    {
                              L->data[j] = L->data[j + 1];
                    }
                    L->Length--;                  //Ԫ�ص������Լ�
                    return 1;
          }
}

/*˳���İ�ֵ���ң���������λ��*/
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

/*˳���İ�λ�úŲ���*/
ElemType GetElem(SeqList L, int i)
{
          if (i<1 || i > L.Length)           //�ж�i�ķ�Χ�Ƿ���Ч
          {
                    printf("�����λ�ô���\n");
                    return 0;
          }
          else
          {
                    return L.data[i - 1];
          }
}

/*���*/
int Length(SeqList L)
{
          return L.Length;
}

/*���ȫ��*/
void PrintList(SeqList L)
{
          for (int i = 0; i < L.Length; ++i)
          {
                    printf("%d   ", L.data[i]);
          }
          printf("\n");
}

/*���Ƿ�Ϊ��*/
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

/*ͨ�����ݽ���ģ��*/
void swap(ElemType* a1, ElemType* a2)
{
          ElemType temp = *a1;
          *a1 = *a2;
          *a2 = temp;
}

/*���Ա����ת*/
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

//������������Ա�l1��l2�ϲ�Ϊһ���µ����Ա�
void Merge(SeqList* L, SeqList* l1, SeqList* l2)
{
          HeapSort(l1);       //�����Ա�l1����
          HeapSort(l2);       //�����Ա�l2����
          L->Length = l1->Length + l2->Length;
          L-> data = (ElemType*)malloc(sizeof(ElemType)*L->Length);      //��չ����
          int i = 0, j = 0, pos = 0;              //i�洢l1��j�洢l2��pos�洢L
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

/*���Ա�Ķ��������*/
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

/*���Ա�Ŀ����������*/
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