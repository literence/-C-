#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef int ElemType;

typedef struct{
    ElemType data;
    int cur;
}component, SLinkList[MAXSIZE];

//算法2.14
void InitSpace_SL(SLinkList space) {
    int i;

    for(i = 0; i < MAXSIZE - 1; ++i) {
        space[i].cur = i + 1;
    }

    space[MAXSIZE - 1].cur = 0;
}

//算法2.15
int Malloc_SL(SLinkList space) {
    int i = space[0].cur;
    space[0].cur = space[i].cur;
    return i;
}

//算法2.16
void Free_SL(SLinkList space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

//算法2.17
void difference_SL(SLinkList space, int* S) {
    // 初始化备用空间
    InitSpace_SL(space);

    // 获取静态链表头结点
    *S = Malloc_SL(space);

    // 让R执行静态链表最后的结点
    int R = *S;

    int m, n;
    printf("请输入集合A的元素个数：");
    scanf("%d", &m);
    printf("请输入集合B的元素个数：");
    scanf("%d", &n);

    printf("请输入 %d 个元素存入集合A：", m);

    // 录入集合A的数据
    for(int j = 1; j <= m; ++j) {
        // 分配结点
        int i = Malloc_SL(space);

        scanf("%d", &space[i].data);

        // 将新结点插入到表尾
        space[R].cur = i;
        R = i;
    }

    // 尾结点的指针置空
    space[R].cur = 0;

    printf("请输入 %d 个元素存入集合B：", n);

    for(int j = 1; j <= n; ++j) {
        int b;
        scanf("%d", &b);

        int p = *S;
        int k = space[*S].cur;

        while(k != space[R].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }

        if(k == space[R].cur) {
            int i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[R].cur;
            space[R].cur = i;

        } else {
            space[p].cur = space[k].cur;
            Free_SL(space, k);
            if(R == k) {
                R = p;
            }
        }
    }
}

void ListTraverse(SLinkList space, int S, void(Visit)(ElemType)) {
    int p;

    // 确保链表存在
    if(S == 0 || space[S].cur == 0) {
        return;
    }

    p = space[S].cur;

    while(p != 0) {
        Visit(space[p].data);
        p = space[p].cur;
    }

    printf("\n");
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {

    //算法2.14 2.15 2.16 2.17
    SLinkList space;
    int S;

    difference_SL(space, &S);

    printf("S = (A-B)∪(B-A) = ");
    ListTraverse(space, S, PrintElem);

    return 0;
}