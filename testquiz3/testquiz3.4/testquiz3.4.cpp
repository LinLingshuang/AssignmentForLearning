/* 链表的创建和节点删除
【问题描述】

从键盘输入10个整数，用这些整数值作为结点数据，生成一个链表，
按顺序输出链表中结点的数值。然后从键盘输入一个待查找整数，在链表中查找该整数，
若找到则删除该整数所在的结点（如果出现多次，全部删除），然后输出删除结点以后的链表。

该题重点在于自定义创建链表函数CreateList()，遍历链表函数TraverseList(pNode pHead)，
删除链表节点函数Del_Node(pNode pHead,int del)。main函数需要调用以上函数实现题目要求，
因此提供基本程序框架作为约束和提示，请独自补完main函数和自定义函数实现文件的编写。
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

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>
using namespace std;
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

    pNode head = NULL;
    pNode tail = NULL;
    int i;
    for (int i = 0; i < 10; i++) {
        pNode pnew = (pNode)malloc(sizeof(Node));
        
        if (pnew == NULL) {
            exit(1);
        }
        scanf("%d", & (pnew->member));
        if (head == NULL) {
            head = pnew;
            tail = pnew;
        }
        pnew->pNext = NULL;
        tail->pNext = pnew;
        tail = pnew;
    }
    return head;
}  
//    遍历链表函数  

void TraverseList(pNode pHead)  

{   pNode p = pHead;
   
    while (p!=NULL) {
        
        printf( "%d",p->member);
        
        p = p->pNext;
        cout << ' ';
    }
    cout << endl;
}  
 
//    删除链表节点函数  

//    第一个参数是头节点，第二个参数是要删除第几个节点

int Del_Node(pNode pHead,int del)  
{  
    if (pHead == NULL) {
        return 0;
    }
    pNode pPre = NULL;
    pNode pcur = pHead;
    int d = 0;
    while (pcur != NULL && pcur->member == del) {
        pHead = pcur->pNext;
        free(pcur);
        pcur = pHead;
        d = 1;
    }
    while (pcur != NULL) {
        if (pcur->member == del) {
            pPre->pNext = pcur->pNext;
            free(pcur);
            pcur = pPre->pNext;
            d = 1;
        }
        else {
            pPre = pcur;
            pcur = pcur->pNext;
        }
    }
    return d ? 1:0;
}
int main()  

{  

    pNode pHead = NULL;                //  定义初始化头节点，等价于 struct Node *pHead == NULL  

    int num;                        //    作为Del_Node函数第二个参数       

    int return_val=-1;  
    pHead = CreateList();            //  创建一个非循环单链表，并将该链表的头结点的地址付给pHead  
    //  因为希冀平台采用UTF-8编码格式，源码中的中文提示会显示乱码,因此将所有中文提示全部注释掉，自己调试时可以加上提示信息。
    TraverseList(pHead);    //  调用遍历链表函数  
   
    scanf("%d",&num); 
    while(return_val!=0)
    return_val=Del_Node(pHead,num); 
      
   
    TraverseList(pHead);
    return 0;  
}  
