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