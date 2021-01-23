//
// Created by Administrator on 2021/1/23 0023.
//

#ifndef ECNUOJ_OJ1_96_H
#define ECNUOJ_OJ1_96_H

#endif //ECNUOJ_OJ1_96_H
/*
 * 求奇数和
Description

输入一批正整数（以零或负数为结束标志），求其中的奇数和。试编写相应程序。


Input
输入一批正整数（以零或负数为结束标志）并用零或负数结尾


Output
输出其奇数的和（整数形式）。


Sample Input 1

1 2 5 6 3 4 0
Sample Output 1

9
 * */
#include "iostream"
#include "vector"
using namespace std;
static void oj(vector<int>vector){
    int val=0;
    for (int i:vector){
        if(i%2!=0){
            val=val+i;
        }

    }
    cout<<val;
}
