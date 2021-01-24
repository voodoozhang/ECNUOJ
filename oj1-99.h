//
// Created by Administrator on 2021/1/24 0024.
//

#ifndef ECNUOJ_OJ1_99_H
#define ECNUOJ_OJ1_99_H
/*
 * 序列求和
Description

输入两个正整数a和n，求a+aa+aaa+aa...a（n个a）之和。试编写相应程序。


Input
输出两个正整数a和n


Output
输出序列之和


Sample Input 1

2 3
Sample Output 1

246
 * */
#include "iostream"
#include "math.h"
using namespace std;
static void oj(int param,int n){
    int res=0;
    int flag=0;
    for (int i = 0; i <n ; ++i) {
        flag=flag+pow(10,i)*param;
        res=res+flag;
    }
    cout<<res;
}
#endif //ECNUOJ_OJ1_99_H
