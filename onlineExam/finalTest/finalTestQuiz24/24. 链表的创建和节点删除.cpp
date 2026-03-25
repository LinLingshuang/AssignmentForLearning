/*24. 链表的创建和节点删除
【问题描述】

从键盘输入10个整数，用这些整数值作为结点数据，生成一个链表，按顺序输出链表中结点的数值。然后从键盘输入一个待查找整数，在链表中查找该整数，若找到则删除该整数所在的结点（如果出现多次，全部删除），然后输出删除结点以后的链表。

该题重点在于自定义创建链表函数CreateList()，遍历链表函数TraverseList(pNode pHead)，删除链表节点函数Del_Node(pNode pHead,int del)。main函数需要调用以上函数实现题目要求，因此提供基本程序框架作为约束和提示，请独自补完main函数和自定义函数实现文件的编写。



#include <stdio.h>  

#include <stdlib.h>  

#include <malloc.h>

//    定义链表中的节点  

typedef struct node  

{  

    int member;                //    节点中的成员  

    struct node *pNext;        //    指向下一个节点的指针  

}Node,*pNode;  

  

//    函数声明  

pNode CreateList();                 //  创建链表函数,功能为创建1个包含10个整数节点的链表  

void TraverseList(pNode );            //  遍历链表函数，并依次显示链表中的每个元素  

int Del_Node(pNode,int );        //    删除链表节点,第一个参数是头节点，第二个参数是删除第几个节点 



//    创建链表函数  

pNode CreateList()  

{  

    

}  

  

//    遍历链表函数  

void TraverseList(pNode pHead)  

{  

   

}  

  

//    删除链表节点函数  

//    第一个参数是头节点，第二个参数是要删除第几个节点

int Del_Node(pNode pHead,int del)  

{  

}

    



int main()  

{  

    pNode pHead = NULL;                //  定义初始化头节点，等价于 struct Node *pHead == NULL  

    int num;                        //    作为Del_Node函数第二个参数       

    int return_val=-1;  

    pHead = CreateList();            //  创建一个非循环单链表，并将该链表的头结点的地址付给pHead  

    //printf("你输入的数据是：");  //  因为希冀平台采用UTF-8编码格式，源码中的中文提示会显示

乱码,因此将所有中文提示全部注释掉，自己调试时可以加上提示信息。

    TraverseList(pHead);    //  调用遍历链表函数  

    

    //printf("请输入要删除节点的值：");  

    scanf("%d",&num); 

    while(return_val!=0)

    return_val=Del_Node(pHead,num);  



          

    //printf("操作完成后的数据是：");  

    TraverseList(pHead);  



    return 0;  

}  

  



【输入形式】

先依次输入10个整数创建链表，显示完整链表后再输入需要删除的节点值

【输出形式】

创建链表后，先显示完整链表，等输入需要删除的节点值后再显示操作后的链表

1 3 4 5 6 7 8 9 0
【样例输入】

1

2

3

4

5

6

7

8

9

0

2


【样例输出】

1 2 3 4 5 6 7 8 9 0

1 3 4 5 6 7 8 9 0

【样例说明】

调试时可加上提示信息，完整输入输出过程如下：

1

2

3

4

5

6

7

8

9

0

你输入的数据是：1 2 3 4 5 6 7 8 9 0

请输入要删除节点的值：2

操作完成后的数据是：1 3 4 5 6 7 8 9 0

【评分标准】*/
#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>

// 定义链表中的节点  
typedef struct node
{
    int member;                // 节点中的成员  
    struct node* pNext;        // 指向下一个节点的指针  
}Node, * pNode;

// 函数声明  
pNode CreateList();                 // 创建链表函数,功能为创建1个包含10个整数节点的链表  
void TraverseList(pNode);          // 遍历链表函数，并依次显示链表中的每个元素  
int Del_Node(pNode, int);           // 删除链表节点,第一个参数是头节点，第二个参数是删除第几个节点 

// 创建链表函数（带头节点，包含10个数据节点）
pNode CreateList()
{
    int i;
    const int node_num = 10; // 固定创建10个整数节点
    // 1. 创建头节点（不存储有效数据，用于统一操作）
    pNode pHead = (pNode)malloc(sizeof(Node));
    if (pHead == NULL) // 内存分配失败判断
    {
        printf("Memory allocation failed for head node!\n");
        exit(EXIT_FAILURE);
    }
    pNode pTail = pHead; // 尾指针，用于快速添加新节点
    pTail->pNext = NULL; // 初始时尾节点后继为NULL

    // 2. 循环创建10个数据节点
    for (i = 0; i < node_num; i++)
    {
        pNode pNew = (pNode)malloc(sizeof(Node));
        if (pNew == NULL)
        {
            printf("Memory allocation failed for new node!\n");
            exit(EXIT_FAILURE);
        }
        scanf("%d", &(pNew->member)); // 输入节点数据
        pNew->pNext = NULL; // 新节点后继置空
        pTail->pNext = pNew; // 尾节点指向新节点
        pTail = pNew; // 尾指针移动到新节点
    }

    return pHead; // 返回头节点
}

// 遍历链表函数
void TraverseList(pNode pHead)
{
    pNode p = pHead->pNext; // 跳过头节点，指向第一个数据节点
    if (p == NULL) // 链表为空判断
    {
        printf("The list is empty!\n");
        return;
    }
    // 循环遍历所有数据节点
    while (p != NULL)
    {
        printf("%d ", p->member); // 打印节点数据
        p = p->pNext; // 移动到下一个节点
    }
    printf("\n"); // 换行优化输出格式
}

// 删除链表节点函数
// 第一个参数是头节点，第二个参数是要删除第几个节点（从1开始计数）
// 返回值：0表示删除成功，-1表示删除失败
int Del_Node(pNode pHead, int del)
{
    // 合法性检查：删除位置不能小于1
    if (del < 1)
    {
        printf("Invalid delete position (must be >=1)!\n");
        return -1;
    }

    pNode p = pHead; // p指向要删除节点的前驱节点，初始为头节点
    int j = 0;

    // 查找第del个节点的前驱节点（循环结束后p指向该前驱）
    while (p->pNext != NULL && j < del - 1)
    {
        p = p->pNext;
        j++;
    }

    // 判断是否存在第del个节点（前驱节点的后继为空，说明位置超出链表长度）
    if (p->pNext == NULL)
    {
        printf("Delete position exceeds the length of the list!\n");
        return -1;
    }

    // 执行删除操作
    pNode pDel = p->pNext; // 保存要删除的节点地址
    p->pNext = pDel->pNext; // 前驱节点跳过要删除的节点
    free(pDel); // 释放删除节点的内存，防止内存泄漏
    pDel = NULL; // 避免野指针

    return 0; // 删除成功
}

int main()
{
    pNode pHead = NULL;                // 定义初始化头节点
    int num;                        // 作为Del_Node函数第二个参数       
    int return_val = -1;

    pHead = CreateList();            // 创建一个非循环单链表
    TraverseList(pHead);    // 调用遍历链表函数  

    scanf("%d", &num);
    // 循环调用删除函数，直到删除成功（return_val=0）
    while (return_val != 0)
    {
        return_val = Del_Node(pHead, num);
        // 若删除失败，重新输入删除位置
        if (return_val != 0)
        {
            printf("Please re-enter the delete position: ");
            scanf("%d", &num);
        }
    }

    TraverseList(pHead);   // 打印删除后的链表

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
