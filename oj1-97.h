//
// Created by Administrator on 2021/1/23 0023.
//
/*
 * 展开式求和
Description

输入一个实数x，计算并输出下式的和，直到最后一项的绝对值小于0.00001，计算结果保留四位小数。要求定义和调用函数fact(n)计算n的阶乘，可以调用pow()函数求幂。试编写相应程序。

S= 1+x+x^2/2! + x^3/3! + x^4/4! +……


Input
输入一个实数x（double类型）


Output
输出序列求和的值，double类型，结果保留4位小数。


Sample Input 1

1
Sample Output 1

2.7183
 * */
#ifndef ECNUOJ_OJ1_97_H
#define ECNUOJ_OJ1_97_H
#include "iostream"
#include "math.h"
#include "typeinfo"
using namespace std;
#endif //ECNUOJ_OJ1_97_H
static int fact(int n){
    if (n==0){
        return 1;
    }
    return n*fact(n-1);
}
static void oj(double n){
    double x=0;
    int i=0;
    while (pow(n,i)/fact(i)<-0.00001||pow(n,i)/fact(i)>0.00001){
        x=x+pow(n,i)/fact(i);
        i++;
    }
    string val=to_string(x);

    if (val[6]-'0'==5||val[6]-'0'==4){
        x=x+0.0001;
    }

    printf("%0.4f\n",x);

}