//
// Created by Administrator on 2021/1/22 0022.
//
/*
 * 排序
Description

给定一个长度为n的数列，将这个数列中重复元素删去，并按从大到小的顺序排列。1<=n<=1000


Input
第一行为一个整数n。第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。


Output
第一行为一个整数n。第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。


Sample Input 1

7
8 3 5 4 2 3 2
Sample Output 1

8 5 4 3 2
 */
#ifndef ECNUOJ_OJ1_56_H
#define ECNUOJ_OJ1_56_H

#endif //ECNUOJ_OJ1_56_H
#include "iostream"
#include "set"
#include "vector"
#include "algorithm"
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
static void oj(set<int>set1){
    set<int>::iterator iterator=set1.begin();
    vector<int>vector;
    for (int i = 0; i <set1.size() ; ++i) {
        vector.push_back(*iterator);
        iterator++;
    }

    sort(vector.begin(),vector.end(),cmp);
    for(int i:vector){
        cout<<i<<" ";
    }
}