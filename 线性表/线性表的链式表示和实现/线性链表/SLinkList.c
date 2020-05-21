#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>     // 提供 strstr 原型

/* 单链表元素类型定义 */
typedef int ElemType;

/*
 * 单链表结构
 *
 * 注：这里的单链表存在头结点
 */
typedef struct LNode {
    ElemType data;      // 数据结点
    struct LNode* next; // 指向下一个结点的指针
} LNode;

// 指向单链表结点的指针
typedef LNode* LinkList;

void ListTraverse(LinkList L, void(Visit)(ElemType)) {
    LinkList p;

    // 确保链表存在
    if(L == NULL || L->next == NULL) {
        return;
    }

    p = L->next;

    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }

    printf("\n");
}


int CreateList_Head(LinkList* L, int n) {
    int i;
    LinkList p;

    // 建立头结点
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    printf("请输入%d个降序元素：", n);
    for(i = 1; i <= n; ++i) {
        // 生成新结点
        p = (LinkList) malloc(sizeof(LNode));
        // 填充数据，并插入到链表中
        scanf("%d", &(p->data));
        p->next = (*L)->next;
        (*L)->next = p;
    }


    return 1;
}

void MergeList(LinkList* La, LinkList* Lb, LinkList* Lc) {
    LinkList pa, pb, pc;

    pa = (*La)->next;
    pb = (*Lb)->next;
    pc = *Lc = *La;                        // 用La的头结点作为Lc的头结点

    // 遍历La和Lb
    while(pa && pb) {
        if(pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    // 插入剩余段
    pc->next = pa ? pa : pb;

    // 释放Lb的头结点所占内存
    free(*Lb);

    *La = NULL;
    *Lb = NULL;
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkList La, Lb, Lc;

    int n = 5;

    printf("作为示例，La长度设定为 %d ，Lb长度设定为 %d ，创建La和Lb...\n", n, n);

    CreateList_Head(&La, n);
    printf("La = ");
    ListTraverse(La, PrintElem);

    CreateList_Head(&Lb, n);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);

    printf("归并La和Lb为Lc = ");
    MergeList(&La, &Lb, &Lc);
    ListTraverse(Lc, PrintElem);

    return 0;
}
