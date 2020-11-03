#include"menu.h"

/*�˵�*/
void Menu(SeqList* list)
{
          int select = 1;
          while (select)
          {
                    printf("*****************************************************************\n");
                    printf("*   [1]  push_back       \t[2] push_front           \t*\n");
                    printf("*   [3]  show_list         \t[4] pop_back             \t*\n");
                    printf("*   [5]  pop_front        \t[6] insert_pos            \t*\n");
                    printf("*   [7]  find                 \t[8] length                   \t*\n");
                    printf("*   [9]  delete_pos      \t[10] delete_val           \t*\n");
                    printf("*   [11]  Sort               \t[12] reverse               \t*\n");
                    printf("*   [13]  Clear             \t[14] Destroy(dangerous) \t*\n");
                    printf("*   [15]  Cls                \t[16]  ExtendSpace        \t*\n");
                    printf("*   [0]  Quit                                                 \t*\n");
                    printf("*****************************************************************\n");
                    printf("��ѡ��>");
                    scanf("%d", &select);
                    if (!select)         //ѡ��ֵΪ0
                    {
                              Destory(list);      //z ��ֹ�ڴ�й©��Ȼ����ڴ�
                              break;              //�˳�������
                    }
                    else
                    {
                              switch (select)
                              {
                                        case 1: //���ݳ�ʼ��β������
                                        {
                                                  printf("��������Ҫ���������(��-1��Ϊ����)��>");
                                                  ElemType item = 0;
                                                  while (scanf("%d", &item) && item != -1)
                                                  {
                                                            push_back(list, item);
                                                  }
                                                  break;
                                        }
                                       
                                        case 2: //���ݳ�ʼ��ͷ������
                                        {
                                                  printf("��������Ҫ���������(��-1��Ϊ����)��>");
                                                  ElemType item = 0;
                                                  while (scanf("%d", &item) && item != -1)
                                                  {
                                                            push_front(list, item);
                                                  }
                                                  break;
                                                  break;
                                        }

                                        case 3:PrintList(*list); break;
                                        case 4:pop_back(list); break;
                                        case 5:pop_front(list); break;
                                        case 6:    //���ݵ�λ�����
                                        {
                                                  printf("��������Ҫ��������ݣ�>");
                                                  ElemType item = 0;  //����
                                                  scanf("%d", &item);
                                                  printf("��������Ҫ�����λ�ã�>"); 
                                                  int pos = 0;   //λ��
                                                  scanf("%d", &pos);
                                                  ListInsert(list, pos, item);
                                                  break;
                                        }

                                        case 7:   //���ݵĲ���
                                        {
                                                  printf("��������Ҫ���ҵ����ݣ�>");
                                                  ElemType item = 0;
                                                  scanf("%d", &item);
                                                  int pos = LocateElem(*list, item);
                                                  if (pos == -1)
                                                  {
                                                            printf("���ҵ�����%d��˳����в�����\n", item);
                                                  }
                                                  else
                                                  {
                                                            printf("���ҵ�����%d��˳����е�λ��Ϊ%d��λ��\n", item, pos);
                                                  }
                                                  break;
                                        }

                                        case 8:printf("˳���ĳ���Ϊ��%d\n", Length(*list)); break;
                                        case 9: //ɾ����������λ���Ԫ��
                                        {
                                                  printf("��������Ҫɾ����Ԫ�����ڵ�λ��>");
                                                  ElemType item;               //���ɾ��������
                                                  int pos = 0;
                                                  scanf("%d", &pos);
                                                  if (!ListDeleteByPos(list, pos, &item))
                                                  {
                                                            printf("����ɾ��ʧ��\n");
                                                  }
                                                  break;
                                        }
                                        case 10://ɾ��ָ��������Ԫ��
                                        {
                                                  printf("��������Ҫɾ����Ԫ�أ�>");
                                                  ElemType num;               //ɾ��������
                                                  ElemType item;               //���ɾ��������
                                                  scanf("%d", &num);
                                                  if (!ListDeleteByNumber(list, num, &item))
                                                  {
                                                            printf("����ɾ��ʧ��\n");
                                                  }
                                                  break;
                                        }
                                        case 11:QuickSort(list, 0, list->Length - 1); break;                  //��������(Ҳ����ѡ�������)
                                        case 12:Reverse(list);break;            //��ת
                                        case 13:ClearList(list); break;
                                        case 14:Destory(list);break;
                                        case 15:system("cls"); break;
                                        case 16:
                                        {
                                                  printf("��������Ҫ��չ�Ŀռ�Ĵ�С��>");
                                                  int size = 0;
                                                  scanf("%d", &size);
                                                  IncreaseSize(list, size);
                                                  break;
                                        }
                                        default:printf("�����������������\n"); break;
                              }
                    }
          }
          return;
}