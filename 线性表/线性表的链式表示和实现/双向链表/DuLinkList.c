//
// Created by li on 2020/5/23.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DuLinkList{
    ElemType data;
    struct DuLinkList *prior;
    struct DuLinkList *next;
}DuLNode, *DuLinkList;

void InitList(DuLinkList* L) {
    *L = (DuLinkList) malloc(sizeof(DuLNode));
    (*L)->next = (*L)->prior = *L;
}

DuLinkList GetElemP_DuL(DuLinkList L, int i) {
    DuLinkList p=L;
    int count=0;

    while(p->next != L && count < i) {
        p = p->next;
        ++count;
    }

    if(count == i) {
        return p;
    }else{
    return L;
    }
}

void ListInsert_Dul(DuLinkList *L, int i, ElemType e){
    DuLinkList p = GetElemP_DuL(L, i);
    DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
}

void ListDelete_Dul(DuLinkList *L, int i, ElemType *e){
    DuLinkList p = GetElemP_DuL(L, i);
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
}

void ListTraverse(DuLinkList L, void(Visit)(ElemType)) {
    DuLinkList p;

    p = L->next;

    while(p != L) {
        Visit(p->data);
        p = p->next;
    }

    printf("\n");
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main() {
    DuLinkList L;
    ElemType e;

    InitList(&L);
    for(int i = 1; i <= 8; i++) {
        printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2 * i);
        ListInsert_Dul(L, i, 2 * i);
    }

        printf("L 中的元素为：L = ");
        ListTraverse(L, PrintElem);

        printf("尝试删除 L 中第 6 个元素...\n");
        ListDelete_Dul(L, 6, &e);
        printf("删除成功，被删除元素是：\"%d\"\n", e);

        printf("删除后的链表：L = ");
        ListTraverse(L, PrintElem);
    return 0;
}






