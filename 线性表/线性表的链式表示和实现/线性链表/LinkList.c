#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode, *LinkList;

//算法2.8
void GetElem_L(LinkList* L, int i, ElemType* e){
    LinkList p;
    p = (*L)->next;
    int j=1;
    while (p && j<i){
        p = p->next;
        ++j;
    }
    *e = p->data;
}


//算法2.9
void ListInsert_L(LinkList* L, int i, ElemType *e){
    LinkList p;
    p = *L;
    int j=0;
    while (p && j < i-1){
        p = p->next;
        ++j;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = *e;
    s->next = p->next;
    p->next = s;
}

//算法2.10
void ListDelete_L(LinkList* L, int i, ElemType *e){
    LinkList p = *L;
    int j = 0;
    while (p->next && j<i-1){
        p = p->next;
        ++j;
    }
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
}

//算法2.11
void CreateList_L(LinkList* L, int n) {
    LinkList p;
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    printf("请输入%d个降序元素：", n);
    for(int i = n; i > 0; --i) {
        p = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &(p->data));
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

//算法2.12
void MergeList_L(LinkList* La, LinkList* Lb, LinkList* Lc) {
    LinkList pa, pb, pc;

    pa = (*La)->next;
    pb = (*Lb)->next;
    *Lc = pc = *La;

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

    pc->next = pa ? pa : pb;

    free(*Lb);
    *La = NULL;
    *Lb = NULL;
}

void ListTraverse(LinkList *L, void(Visit)(ElemType)) {
    LinkList p;

    // 确保链表存在
    if((*L) == NULL || (*L)->next == NULL) {
        return;
    }

    p = (*L)->next;

    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }

    printf("\n");
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {

    int n = 5;


    //算法2.8
    int *e;
    LinkList L;
    CreateList_L(&L, n);
    ListTraverse(&L, PrintElem);
    GetElem_L(&L, 2, e);
    printf("第 i 个元素是 %d \n", *e);


    //算法2.9
    int insert = 6;
    ListInsert_L(&L, 3, &insert);
    ListTraverse(&L, PrintElem);

    //算法2.10
    int delete;
    ListDelete_L(&L, 3, &delete);
    ListTraverse(&L, PrintElem);



    LinkList La, Lb, Lc;

    //算法2.11
    CreateList_L(&La, n);
    printf("La = ");
    ListTraverse(&La, PrintElem);

    CreateList_L(&Lb, n);
    printf("Lb = ");
    ListTraverse(&Lb, PrintElem);

    printf("归并La和Lb为Lc = ");
    //算法2.12
    MergeList_L(&La, &Lb, &Lc);
    ListTraverse(&Lc, PrintElem);

    return 0;
}
