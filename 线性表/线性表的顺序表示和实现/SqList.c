//
// Created by li on 2020/5/20.
//

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

//算法2.3
int InitList_Sq(SqList *L){
    (*L).elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return 1;
}

//算法2.4
int ListInsert_Sq(SqList *L, int i, ElemType e){
    if ((*L).length >= (*L).listsize){
        ElemType* newbase = (ElemType*)realloc((*L).elem, (((*L).listsize)+LISTINCREMENT) * sizeof(ElemType));
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    ElemType *q = &((*L).elem[i]);
    for(ElemType *p = &((*L).elem[(*L).length-1]); p >= q; --p){
        *(p+1) = *p;
    }
    *q = e;
    ++(*L).length;
    return 1;
}


//算法2.5
int ListDelete_Sq(SqList *L, int i, ElemType *e){
    ElemType *p = &((*L).elem[i]);
    *e = *p;
    ElemType *q;
    q = (*L).elem + (*L).length-1;
    for(++p; p <= q; ++p){
        *(p-1) = *p;
    }
    --(*L).length;
    return 1;
}

int compare(ElemType e1, ElemType e2){
    return e1 == e2;
}

//算法2.6
int LocateElem_Sq(SqList *L, ElemType e, int(*compare)(ElemType, ElemType)){
    int i = 1;
    ElemType *p;
    p= (*L).elem;
    while (i <= (*L).length && !(*compare)(*p++, e)){
        ++i;
    }
    if (i <= (*L).length){
        return i;
    } else{
        return 0;
    }
}


//算法2.7
void MergeList_Sq(SqList *La, SqList *Lb, SqList *Lc){
    ElemType *pa;
    pa = (*La).elem;
    ElemType *pb;
    pb = (*Lb).elem;
    (*Lc).listsize = (*Lc).length =(*La).length + (*Lb).length;
    ElemType *pc;
    pc = (*Lc).elem = (ElemType*)malloc((*Lc).listsize*sizeof(ElemType));
    ElemType *pa_last;
    pa_last = (*La).elem + (*La).length-1;
    ElemType *pb_last;
    pb_last = (*Lb).elem + (*Lb).length-1;
    while (pa <= pa_last && pb <= pb_last){
        if (*pa <= *pb){
            *pc++ = *pa++;
        }else{
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last){
        *pc++ = *pa++;
    }
    while (pb <= pb_last){
        *pc++ = *pb++;
    }
}


void ListTraverse(SqList L, void(Visit)(ElemType)) {
    int i;
    for(i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }

    printf("\n");
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}

int main(){
    SqList L;
    InitList_Sq(&L);

    for(int i = 0; i <= 8; i++) {
        printf("在 L 第 %d 个位置插入 \"%d\"...\n", i, 2 * i);
        ListInsert_Sq(&L, i, 2 * i);
    }

    printf("L 中的元素为：L = ");
    ListTraverse(L, PrintElem);

    int i=2;
    int e;
    ListDelete_Sq(&L, i, &e);
    printf("删除的数字：%d\n", e);

    int locate=2;
    printf("第一个满足值与 locate 满足 compare() 的元素的位序%d\n", LocateElem_Sq(&L, locate, *compare));

    SqList La, Lb, Lc;
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    //InitList_Sq(&Lc);
    for(int i = 0; i <= 8; i++) {
        printf("在 La 第 %d 个位置插入 \"%d\"...\n", i, 2 * i);
        ListInsert_Sq(&La, i, 2 * i);
    }
    printf("La 中的元素为：La = ");
    ListTraverse(La, PrintElem);

    for(int i = 0; i <= 8; i++) {
        printf("在 Lb 第 %d 个位置插入 \"%d\"...\n", i, 2*i+1);
        ListInsert_Sq(&Lb, i, 2*i+1);
    }
    printf("Lb 中的元素为：Lb = ");
    ListTraverse(Lb, PrintElem);

    MergeList_Sq(&La, &Lb, &Lc);
    printf("Lc 中的元素为：Lc = ");
    ListTraverse(Lc, PrintElem);
    return 0;
}
