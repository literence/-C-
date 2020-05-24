#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float coef;
    int expn;
} ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, * Link, * Position;

typedef struct {
    Link head, tail;
    int len;
} ELinkList, Polynomial;

//创建带头结点的链表
int MakeNode(Link* p, ElemType e) {
    *p = (Link) malloc(sizeof(LNode));
    (*p)->data = e;
    (*p)->next = NULL;
    return 1;
}

//释放头结点
void FreeNode(Link* p) {
    free(*p);
    *p = NULL;
}

int InitList(ELinkList* L) {
    Link p;
    p = (Link) malloc(sizeof(LNode));
    p->next = NULL;
    (*L).head = (*L).tail = p;
    (*L).len = 0;

    return 1;
}

int ClearList(ELinkList* L) {
    Link p = (*L).head->next;

    while(p != NULL) {
        Link q = p->next;
        free(p);
        p = q;
    }

    (*L).head->next = NULL;
    (*L).tail = (*L).head;
    (*L).len = 0;

    return 1;
}


int DestroyPolyn(ELinkList* L) {
    ClearList(L);
    free((*L).head);
    (*L).head = (*L).tail = NULL;
    return 1;
}


/*
 * 这里首先会查找与元素e满足Compare()==0的元素，如果找到，使用q存储其引用，并返回1。
 * 如果不存在上述引用，则查找首个与元素e满足Compare()>0的元素的前驱，并返回0。
 * 如果链表中的元素均大于e，q存储头结点引用。
 * 如果链表中的元素均小于e，q存储尾结点引用。
 * 其它情形下，会将q置空。
 *
 *【备注】
 * 1.元素e是Compare函数第二个形参
 */
int LocateElem(ELinkList L, ElemType e, Position* q, int(Compare)(ElemType, ElemType)) {
    *q = NULL;

    Position pre = L.head;
    Position p = pre->next;

    while(p != NULL && Compare(p->data, e) < 0) {
        pre = p;
        p = p->next;
    }

    // 找到了与e满足"相等"条件的元素
    if(p != NULL && Compare(p->data, e) == 0) {
        *q = p;
        return 1;
    }

    // 所有元素均小于e，或者p元素大于e，又或者为空表
    *q = pre;

    return 0;
}

ElemType GetCurElem(Link p) {
    ElemType e;

    if(p == NULL) {
        e.coef = 0.0f;
        e.expn = -1;
        return e;
    }

    return p->data;
}

/*
 * 插入
 *
 * 将s结点插入到h结点后面，成为h后面的第一个结点
 *
 *【备注】
 * 教材中对于该方法的描述有些问题，这里是修正过的版本
 */
int InsFirst(ELinkList* L, Link h, Link s) {
    s->next = h->next;
    h->next = s;

    // 若h为尾结点，则需要更新尾结点
    if(h == (*L).tail) {
        (*L).tail = h->next;
    }

    (*L).len++;

    return 1;
}

//删除h结点后的第一个结点，并用q存储被删除结点的引用
int DelFirst(ELinkList* L, Link h, Link* q) {
    *q = h->next;

    h->next = (*q)->next;

    // 将被删除结点变成孤立的结点
    (*q)->next = NULL;

    // 如果h后只有一个结点，更改尾结点指针
    if(h->next == NULL) {
        (*L).tail = h;
    }

    // 并不释放被删结点所占空间
    (*L).len--;

    return 1;
}

int Append(ELinkList* L, Link s) {
    int count= 0;
    (*L).tail->next = s;

    // 确定新的尾结点位置
    while(s != NULL) {
        (*L).tail = s;
        s = s->next;
        count++;
    }

    (*L).len += count;

    return 1;
}

int Cmp(ElemType c1, ElemType c2) {
    int i = c1.expn - c2.expn;
    return (i < 0) ? -1 : ((i == 0) ? 0 : 1);
}

void CreatPolyn(Polynomial* P, int m) {
    //创建带头结点的链表
    InitList(P);
    // 获取多项式头指针
    Position h = (*P).head;

    // 为头结点填充数据
    ElemType e;
    e.coef = 0.0f;
    e.expn = -1;
    h->data = e;

    printf("请输入 %d 个元素：\n", m);

    for(int i = 1; i <= m; i++) {
        printf("请输入第 %d 组系数和指数：", i);
        scanf("%f %d", &(e.coef), &(e.expn));

        // 如果当前链表中不存在该指数项
        Position q;
        Link s;
        if(LocateElem(*P, e, &q, Cmp) == 0 && q != NULL) {
            // 创建新结点
            if(MakeNode(&s, e) == 1) {
                // 在q结点之后插入s
                InsFirst(P, q, s);
            }
        }
    }
}

//算法2.23
void AddPolyn(Polynomial* Pa, Polynomial* Pb) {
    float sum;

    // ha、hb分别指向Pa、Pb头结点
    Position ha = (*Pa).head;
    Position hb = (*Pb).head;

    // qa、qb分别指向Pa、Pb的第一个结点
    Position qa = ha->next;
    Position qb = hb->next;

    // qa、qb均非空
    while(qa && qb) {
        // a和b为两表中当前比较元素
        ElemType a = GetCurElem(qa);
        ElemType b = GetCurElem(qb);

        //比较当前元素的指数大小
        switch(Cmp(a, b)) {
            // 多项式Pa中当前结点的指数值较小
            case -1: {
                ha = qa;
                qa = qa->next;
            }
                break;

                // 两者数值相等
            case 0: {
                sum = a.coef + b.coef;

                // 相加不能抵消时更新Pa结点的系数值
                if(sum != 0.0) {
                    qa->data.coef = sum;
                    // ha后移
                    ha = qa;

                    //相加抵消时，删除Pa中当前结点
                } else {
                    // 删除ha后面的结点（其实删的就是qa）
                    DelFirst(Pa, ha, &qa);
                    // 释放被删除结点所占空间
                    FreeNode(&qa);
                }

                // 删除Pb中扫描过的结点
                DelFirst(Pb, hb, &qb);
                // 释放被删除结点所占空间
                FreeNode(&qb);

                // qa、qb均后移
                qa = ha->next;
                qb = hb->next;
            }
                break;

                // 多项式Pb中当前结点的指数值较小
            case 1: {
                // 摘下Pb当前结点
                DelFirst(Pb, hb, &qb);

                // 将摘下结点链入Pa中
                InsFirst(Pa, ha, qb);

                ha = ha->next;
                qb = hb->next;
            }
                break;
        }//switch
    }//while

    // 若Pb还未扫描完，将剩余项链接到Pa后
    if(qb != NULL) {
        Append(Pa, qb);
    }

    // 释放Pb头结点
    FreeNode(&hb);

    // 设置Pb为销毁状态
    (*Pb).head = (*Pb).tail = NULL;
    (*Pb).len = 0;
}


void SubtractPolyn(Polynomial* Pa, Polynomial* Pb) {
    // ha、hb分别指向Pa、Pb头结点
    Position ha = (*Pa).head;
    Position hb = (*Pb).head;

    // qa、qb分别指向Pa、Pb的当前结点
    Position qa = ha->next;
    Position qb = hb->next;

    // qa、qb均非空
    while(qa && qb) {
        // a和b为两表中当前比较元素
        ElemType a = GetCurElem(qa);
        ElemType b = GetCurElem(qb);

        // 比较当前元素的指数大小
        switch(Cmp(a, b)) {
            // 多项式Pa中当前结点的指数值较小
            case -1: {
                ha = qa;
                qa = ha->next;
            }
                break;

                // 两者数值相等
            case 0: {
                float sum = a.coef - b.coef;

                // 相减不能抵消时更新Pa结点的系数值
                if(sum != 0.0) {
                    // 更新系数
                    qa->data.coef = sum;
                    // ha后移
                    ha = qa;

                    // 相减抵消时，删除Pa中当前结点
                } else {
                    // 删除ha后面的结点（其实删的就是qa）
                    DelFirst(Pa, ha, &qa);
                    // 释放被删除结点所占空间
                    FreeNode(&qa);
                }

                // 删除Pb中扫描过的结点
                DelFirst(Pb, hb, &qb);
                // 释放被删除结点所占空间
                FreeNode(&qb);

                // qa、qb均后移
                qa = ha->next;
                qb = hb->next;
            }
                break;

                // 多项式Pb中当前结点的指数值较小
            case 1: {
                // 摘下Pb当前结点
                DelFirst(Pb, hb, &qb);

                // 改变当前结点符号
                qb->data.coef = -qb->data.coef;

                // 将摘下结点链入Pa中
                InsFirst(Pa, ha, qb);

                ha = ha->next;
                qb = hb->next;
            }
                break;

        }//switch
    }//while

    // 若Pb还未扫描完，将剩余项的系数取反后链接到Pa后
    if(qb != NULL) {
        // 改变剩余项的符号
        for(Position r = qb; r != NULL; r = r->next) {
            r->data.coef = -(r->data.coef);
        }

        Append(Pa, qb);
    }

    // 释放Pb头结点
    FreeNode(&hb);

    // 设置Pb为销毁状态
    (*Pb).head = (*Pb).tail = NULL;
    (*Pb).len = 0;
}

/*
 * 乘法
 *
 * 一元多项式乘法Pa=Pa*Pb，
 * 计算完成后，计算结果存到Pa中，并将Pb销毁。
 */
void MultiplyPolyn(Polynomial* Pa, Polynomial* Pb) {
    Link s;

    // 获取两个多项式的长度
    int la = (*Pa).len;
    int lb = (*Pb).len;

    // ha、hb分别指向Pa、Pb头结点
    Position ha = (*Pa).head;
    Position hb = (*Pb).head;

    // 累加计算结果
    Polynomial Pc, Ptmp;
    InitList(&Pc);

    Position qa, qb;
    // 遍历Pa中的元素
    for(int i = 1; i <= la; i++) {
        // 存储临时计算结果
        InitList(&Ptmp);

        // 逐个摘下Pa中的结点
        DelFirst(Pa, ha, &qa);

        // 遍历Pb中所有结点，与Pa中摘下的结点进行运算
        int j;
        ElemType e;
        for(j = 1, qb = hb->next; j <= lb; j++, qb = qb->next) {
            e.coef = qa->data.coef * qb->data.coef;    //系数相乘
            e.expn = qa->data.expn + qb->data.expn;    //指数相加

            // 创建新结点存储结算结果
            MakeNode(&s, e);

            // 添加到临时多项式
            Append(&Ptmp, s);
        }

        // 将新的多项式累加到Pc上
        AddPolyn(&Pc, &Ptmp);
    }

    // 将所有结果添加到Pa上
    AddPolyn(Pa, &Pc);

    // 销毁多项式Pb
    DestroyPolyn(Pb);
}

void PrintPolyn(Polynomial P) {
    Link p = P.head->next;
    for(int i = 1; i <= P.len; i++) {
        if(p->data.coef == 0.0f) {
            continue;
        }

        if(i == 1) {
            printf("%g", p->data.coef);
        } else {
            if(p->data.coef > 0) {
                printf(" + ");
                printf("%g", p->data.coef);
            } else {
                printf(" - ");
                printf("%g", -p->data.coef);
            }
        }

        if(p->data.expn) {
            printf("x");

            if(p->data.expn != 1) {
                printf("^%d", p->data.expn);
            }
        }

        p = p->next;
    }

    printf("\n");
}



int main() {

    Polynomial Pa, Pb;

    int m=2, n=4;

    CreatPolyn(&Pa, m);
    CreatPolyn(&Pb, n);
    printf("La 的项数为 %d ，Lb 的项数为 %d\n", Pa.len, Pb.len);
    AddPolyn(&Pa, &Pb);
    printf("Pa = Pa + Pb = ");
    PrintPolyn(Pa);

    CreatPolyn(&Pa, m);
    CreatPolyn(&Pb, n);
    SubtractPolyn(&Pa, &Pb);
    printf("Pa = Pa - Pb = ");
    PrintPolyn(Pa);

    CreatPolyn(&Pa, m);
    CreatPolyn(&Pb, n);
    MultiplyPolyn(&Pa, &Pb);
    printf("Pa = Pa * Pb = ");
    PrintPolyn(Pa);
    return 0;
}