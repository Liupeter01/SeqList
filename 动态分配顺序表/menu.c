#include"menu.h"

/*菜单*/
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
                    printf("请选择：>");
                    scanf("%d", &select);
                    if (!select)         //选择值为0
                    {
                              Destory(list);      //z 防止内存泄漏仍然清空内存
                              break;              //退出并结束
                    }
                    else
                    {
                              switch (select)
                              {
                                        case 1: //数据初始化尾部插入
                                        {
                                                  printf("请输入需要插入的数据(以-1作为结束)：>");
                                                  ElemType item = 0;
                                                  while (scanf("%d", &item) && item != -1)
                                                  {
                                                            push_back(list, item);
                                                  }
                                                  break;
                                        }
                                       
                                        case 2: //数据初始化头部插入
                                        {
                                                  printf("请输入需要插入的数据(以-1作为结束)：>");
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
                                        case 6:    //数据的位序插入
                                        {
                                                  printf("请输入需要插入的数据：>");
                                                  ElemType item = 0;  //数据
                                                  scanf("%d", &item);
                                                  printf("请输入需要插入的位置：>"); 
                                                  int pos = 0;   //位置
                                                  scanf("%d", &pos);
                                                  ListInsert(list, pos, item);
                                                  break;
                                        }

                                        case 7:   //数据的查找
                                        {
                                                  printf("请输入需要查找的数据：>");
                                                  ElemType item = 0;
                                                  scanf("%d", &item);
                                                  int pos = LocateElem(*list, item);
                                                  if (pos == -1)
                                                  {
                                                            printf("查找的数据%d在顺序表中不存在\n", item);
                                                  }
                                                  else
                                                  {
                                                            printf("查找的数据%d在顺序表中的位序为%d的位置\n", item, pos);
                                                  }
                                                  break;
                                        }

                                        case 8:printf("顺序表的长度为：%d\n", Length(*list)); break;
                                        case 9: //删除数据所在位序的元素
                                        {
                                                  printf("请输入需要删除的元素所在的位序：>");
                                                  ElemType item;               //存放删除的数据
                                                  int pos = 0;
                                                  scanf("%d", &pos);
                                                  if (!ListDeleteByPos(list, pos, &item))
                                                  {
                                                            printf("数据删除失败\n");
                                                  }
                                                  break;
                                        }
                                        case 10://删除指定的数据元素
                                        {
                                                  printf("请输入需要删除的元素：>");
                                                  ElemType num;               //删除的数据
                                                  ElemType item;               //存放删除的数据
                                                  scanf("%d", &num);
                                                  if (!ListDeleteByNumber(list, num, &item))
                                                  {
                                                            printf("数据删除失败\n");
                                                  }
                                                  break;
                                        }
                                        case 11:QuickSort(list, 0, list->Length - 1); break;                  //快速排序(也可以选择堆排序)
                                        case 12:Reverse(list);break;            //逆转
                                        case 13:ClearList(list); break;
                                        case 14:Destory(list);break;
                                        case 15:system("cls"); break;
                                        case 16:
                                        {
                                                  printf("请输入需要扩展的空间的大小：>");
                                                  int size = 0;
                                                  scanf("%d", &size);
                                                  IncreaseSize(list, size);
                                                  break;
                                        }
                                        default:printf("输入错误请重新输入\n"); break;
                              }
                    }
          }
          return;
}