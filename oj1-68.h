//
// Created by Administrator on 2021/1/24 0024.
//
/*
 * Description

本题目要求编写程序统计一行字符中单词的个数。所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。


Input
输入给出一行字符。


Output
在一行中输出单词个数。


Sample Input 1

Let's go to room 209.
Sample Output 1

5
 * */

#ifndef ECNUOJ_OJ1_68_H
#define ECNUOJ_OJ1_68_H

#include "string"
#include "iostream"
#include "vector"

using namespace std;

static void oj(string param) {
    vector<string>vector1;
    int i=0;
    bool start= true;
    string val="";
        while (start){
            while (param[i]==' '){
                if (i+1>=param.size()){
                    start= false;
                    break;
                } else{
                    i++;
                }
            }
            while (param[i]!=' '){
                val=val+param[i];
                if (i+1>=param.size()){
                    start= false;
                    break;
                } else{
                    i++;
                }
            }
            if (val==""){
            } else{
                vector1.push_back(val);
            }
            val="";
        }

    cout<<vector1.size();
}

#endif //ECNUOJ_OJ1_68_H
