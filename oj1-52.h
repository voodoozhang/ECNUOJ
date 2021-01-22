//
// Created by Administrator on 2021/1/22 0022.
//降序排序
//Description
//
//输入四个数，实现降序排序
//
//
//Input
//输入四个整数
//
//
//Output
//按降序输出
//
//
//Sample Input 1
//
//4 5 2 6
//Sample Output 1
//
//[6, 5, 4, 2]
#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;
static void oj(vector<int>vector){
    sort(vector.begin(),vector.end());
    cout<<"[";
    for (int i = vector.size()-1; i >=0 ; --i) {
        if (i>0){
            cout<<vector[i]<<",";
        } else{
            cout<<vector[i];
        }

    }
    cout<<"]";
}
