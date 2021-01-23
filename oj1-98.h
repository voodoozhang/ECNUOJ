//
// Created by Administrator on 2021/1/23 0023.
//

#ifndef ECNUOJ_OJ1_98_H
#define ECNUOJ_OJ1_98_H
#include "iostream"
using namespace std;
double fact1(int n){
    if (n==1){
        return 2;
    } else if (n==2){
        return 3;
    } else{
        int i=2;

        int val=3;
        for (int k = 3; k <=n; ++k) {
            int p=val;
            val=val+i;
            i=p;
        }
        return val;
    }
}
double fact2(int n){
    if (n==1){
        return 1;
    } else if (n==2){
        return 2;
    } else{
        int i=1;

        int val=2;
        for (int k = 3; k <=n; ++k) {
            int p=val;
            val=val+i;
            i=p;
        }
        return val;
    }
}
static void oj(int n){
    double val=0;
    for (int i = 1; i <n+1 ; ++i) {
       val=val+fact1(i)/fact2(i);
    }
    printf("%0.2f\n",val);

}
#endif //ECNUOJ_OJ1_98_H
