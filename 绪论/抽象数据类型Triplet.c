#include "stdio.h"
#include "stdlib.h"

typedef int* Triplet;//定义Triplet为指针类型;

void InitTriplet(Triplet *T, int v1, int v2, int v3){
    *T = (int *)malloc(sizeof(int) * 3);
    (*T)[0] = v1;
    (*T)[1] = v2;
    (*T)[2] = v3;
}
//销毁三元组
void DestroyTriplet(Triplet *T){
    free(*T);
    *T = NULL;
}

//根据下标获取三元组下标的值
void Get(Triplet *T, int i, int *e){
    *e = (*T)[i];
}

//向三元组添加元素
void Put(Triplet *T, int i, int e){
    (*T)[i-1] = e;
}

//判断三元组是否是升序排列
int IsAcending(Triplet *T){
    if(((*T)[0] < (*T)[1]) && ((*T)[1] < (*T)[2]))
    {
        return 1;
    }
    return 0;
}

//判断三元组是否是降序排列
int IsDcending(Triplet *T){
    if (((*T)[0] > (*T)[1]) && ((*T)[1]) > (*T)[2])
    {
        return 1;
    }
    return 0;
}

//获取三元组中的最大值
void Max(Triplet *T, int *max){
    *max = ((*T)[0] >= (*T)[1]) ? (((*T)[0] >= (*T)[2]) ? (*T)[0] : (*T)[2])
            : (((*T)[1] >= (*T)[2]) ? (*T)[1] : (*T)[2]);
}

//获取三元组中的最小值
void Min(Triplet *T, int *min) {
    *min = ((*T)[0] <= (*T)[1]) ? (((*T)[0] <= (*T)[2]) ? (*T)[0] : (*T)[2])
            : (((*T)[1] <= (*T)[2]) ? (*T)[1] : (*T)[2]);
}

int main(){
    Triplet T;
    int v1 = 1, v2 = 2, v3 = 3, e, max, min;
//初始化三元组
    InitTriplet(&T, v1, v2, v3);

    Get(&T, 1, &e);

    Put(&T, 3, 5);

    Max(&T, &max);

    Min(&T, &min);

    printf("当前元素的值为%d\n",e);

    printf("当前三元组中的最大值为%d\n", max);

    printf("当前三元组中的最小值为%d\n", min);

    printf("是否按升序排列：%d\n", IsAcending(&T));

    printf("是否按降序排列：%d\n", IsDcending(&T));

    DestroyTriplet(&T);
}