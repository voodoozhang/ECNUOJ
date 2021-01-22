#include <iostream>
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

/*
1-15
数的读法
Description

Tom教授正在给研究生讲授一门关于基因的课程，有一件事情让他颇为头疼：一条染色体上有成千上万个碱基对，它们从0开始编号，到几百万，几千万，甚至上亿。

比如说，在对学生讲解第1234567009号位置上的碱基时，光看着数字是很难准确的念出来的。

所以，他迫切地需要一个系统，然后当他输入12 3456 7009时，会给出相应的念法：

十二亿三千四百五十六万七千零九

用汉语拼音表示为

shi er yi san qian si bai wu shi liu wan qi qian ling jiu

这样他只需要照着念就可以了。

你的任务是帮他设计这样一个系统：给定一个阿拉伯数字串，你帮他按照中文读写的规范转为汉语拼音字串，相邻的两个音节用一个空格符格开。

注意必须严格按照规范，比如说“10010”读作“yi wan ling yi shi”而不是“yi wan ling shi”，“100000”读作“shi wan”而不是“yi shi wan”，“2000”读作“er qian”而不是“liang qian”。


Input
有一个数字串，数值大小不超过2,000,000,000。


Output
是一个由小写英文字母，逗号和空格组成的字符串，表示该数的英文读法。


Sample Input 1

1234567009
Sample Output 1

shi er yi san qian si bai wu shi liu wan qi qian ling jiu
 */
//static void func(int a) {
//    string res;
//    int bil = a / 100000000;
//    a = a - bil * 100000000;
//    int mil = a / 10000;
//    int last = a - mil * 10000;
//    int q = bil / 10;
//    int w = bil % 10;
//    int p = mil / 1000;
//    int i = (mil % 1000) / 100;
//    int j = ((mil % 1000) % 100) / 10;
//    int y = ((mil % 1000) % 100) % 10;
//    int e = last / 1000;
//    int t = (last % 1000) / 100;
//    int f = ((last % 1000) % 100) / 10;
//    int g = ((last % 1000) % 100) % 10;
//    if (bil == 0 && mil == 0 && last == 0) {
//        res = res + "ling ";
//    } else if (bil == 0 && mil == 0 && last != 0) {
//        switch (e) {
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "er qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (t) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "er bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (e != 0 && f != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (f) {
//            case 0:
//                if ((e != 0 || t != 0) && (g != 0)) {
//                    res = res + "ling ";
//                }
//                break;
//            case 1:
//                if (e == 0 && t == 0) {
//                    res = res + "shi ";
//                } else {
//                    res = res + "yi shi ";
//                }
//
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (g) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//    } else if (bil == 0 && mil != 0 && last == 0) {
//        switch (p) {
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "er qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (i) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "er bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (e != 0 && f != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (j) {
//            case 0:
//                if ((e != 0 || t != 0) && (g != 0)) {
//                    res = res + "ling ";
//                }
//                break;
//            case 1:
//                if (e == 0 && t == 0) {
//                    res = res + "shi ";
//                } else {
//                    res = res + "yi shi ";
//                }
//
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (y) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//        res = res + "wan ";
//    } else if (bil == 0 && mil != 0 && last != 0) {
//        switch (p) {
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "er qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (i) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "er bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (p!= 0 && j != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (j) {
//            case 0:
//                if ((p != 0 || i != 0) && (y!= 0)) {
//                    res = res + "ling ";
//
//
//                }
//                break;
//            case 1:
//                if (p == 0 && i == 0) {
//                    res = res + "shi ";
//                } else {
//                    res = res + "yi shi ";
//                }
//
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (y) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//        res = res + "wan ";
//        switch (e) {
//            case 0:
//                res = res + "ling ";
//                break;
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "er qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (t) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "er bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (e != 0 && f != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (f) {
//            case 0:
//                if ((e != 0 || t != 0) && (g != 0)) {
//                    res = res + "ling ";
//                }
//                break;
//            case 1:
//                if (e==0&&t==0){
//                    res=res+"shi ";
//                } else{
//                    res = res + "yi shi ";
//                }
//
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (g) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//    } else if (bil != 0 && mil == 0 && last == 0) {
//        switch (q) {
//            case 1:
//                res = res + "shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//            default:;
//                break;
//        }
//        switch (w) {
//            case 1:
//                res=res+"yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//            default:;
//                break;
//        }
//        res=res+"yi ";
//    } else if (bil != 0 && mil == 0 && last != 0) {
//        switch (q) {
//            case 1:
//                res = res + "shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//            default:;
//                break;
//        }
//        switch (w) {
//            case 1:
//                res=res+"yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//            default:;
//                break;
//        }
//        res=res+"yi ";
//        switch (e) {
//            case 0:
//                res = res + "ling ";
//                break;
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "liang qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (t) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "liang bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (e != 0 && f != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (f) {
//            case 0:
//                if ((e != 0 || t != 0) && (g != 0)) {
//                    res = res + "ling ";
//                }
//                break;
//            case 1:
//                    res = res + "yi shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (g) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//    } else if (bil != 0 && mil != 0 && last == 0) {
//        switch (q) {
//            case 1:
//                res = res + "shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//            default:;
//                break;
//        }
//        switch (w) {
//            case 1:
//                res=res+"yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//            default:;
//                break;
//        }
//        res=res+"yi ";
//        switch (p) {
//            case 0:
//                res=res+"ling ";
//                break;
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "liang qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (i) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "liang bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (e != 0 && f != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (j) {
//            case 0:
//                if ((e != 0 || t != 0) && (g != 0)) {
//                    res = res + "ling ";
//                }
//                break;
//            case 1:
//                    res = res + "yi shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (y) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//        res = res + "wan ";
//
//    } else if (bil != 0 && mil != 0 && last != 0) {
//        switch (q) {
//            case 1:
//                res = res + "shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//            default:;
//                break;
//        }
//        switch (w) {
//            case 1:
//                res=res+"yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//            default:;
//                break;
//        }
//        res=res+"yi ";
//        switch (p) {
//            case 0:
//                res=res+"ling ";
//                break;
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "liang qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (i) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "liang bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (e != 0 && f != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (j) {
//            case 0:
//                if ((e != 0 || t != 0) && (g != 0)) {
//                    res = res + "ling ";
//                }
//                break;
//            case 1:
//                res = res + "yi shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (y) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//        res = res + "wan ";
//        switch (e) {
//            case 0:
//                res = res + "ling ";
//                break;
//            case 1:
//                res = res + "yi qian ";
//                break;
//            case 2:
//                res = res + "liang qian ";
//                break;
//            case 3:
//                res = res + "san qian ";
//                break;
//            case 4:
//                res = res + "wi qian ";
//                break;
//            case 5:
//                res = res + "wu qian ";
//                break;
//            case 6:
//                res = res + "liu qian ";
//                break;
//            case 7:
//                res = res + "qi qian ";
//                break;
//            case 8:
//                res = res + "ba qian ";
//                break;
//            case 9:
//                res = res + "jiu qian ";
//                break;
//            default:
//                break;
//        }
//        switch (t) {
//            case 1:
//                res = res + "yi bai ";
//                break;
//            case 2:
//                res = res + "liang bai ";
//                break;
//            case 3:
//                res = res + "san bai ";
//                break;
//            case 4:
//                res = res + "si bai ";
//                break;
//            case 5:
//                res = res + "wu bai ";
//                break;
//            case 6:
//                res = res + "liu bai ";
//                break;
//            case 7:
//                res = res + "qi bai ";
//                break;
//            case 8:
//                res = res + "ba bai ";
//                break;
//            case 9:
//                res = res + "jiu bai ";
//                break;
//            case 0:
//                if (e != 0 && f != 0) {
//                    res = res + "ling ";
//                }
//                break;
//
//        }
//        switch (f) {
//            case 0:
//                if ((e != 0 || t != 0) && (g != 0)) {
//                    res = res + "ling ";
//                }
//                break;
//            case 1:
//                res = res + "yi shi ";
//                break;
//            case 2:
//                res = res + "er shi ";
//                break;
//            case 3:
//                res = res + "san shi ";
//                break;
//            case 4:
//                res = res + "si shi ";
//                break;
//            case 5:
//                res = res + "wu shi ";
//                break;
//            case 6:
//                res = res + "liu shi ";
//                break;
//            case 7:
//                res = res + "qi shi ";
//                break;
//            case 8:
//                res = res + "ba shi ";
//                break;
//            case 9:
//                res = res + "jiu shi ";
//                break;
//
//        }
//        switch (g) {
//            case 1:
//                res = res + "yi ";
//                break;
//            case 2:
//                res = res + "er ";
//                break;
//            case 3:
//                res = res + "san ";
//                break;
//            case 4:
//                res = res + "si ";
//                break;
//            case 5:
//                res = res + "wu ";
//                break;
//            case 6:
//                res = res + "liu ";
//                break;
//            case 7:
//                res = res + "qi ";
//                break;
//            case 8:
//                res = res + "ba ";
//                break;
//            case 9:
//                res = res + "jiu ";
//                break;
//
//        }
//    }
//
//    cout << res;
//
//}


/*
 * 1-18
 * 字符串对比
Description

给定两个仅由大写字母或小写字母组成的字符串(长度介于1到10之间)，它们之间的关系是以下4中情况之一：

1：两个字符串长度不等。比如 Beijing 和 Hebei

2：两个字符串不仅长度相等，而且相应位置上的字符完全一致(区分大小写)，比如 Beijing 和 Beijing

3：两个字符串长度相等，相应位置上的字符仅在不区分大小写的前提下才能达到完全一致（也就是说，它并不满足情况2）。比如 beijing 和 BEIjing

4：两个字符串长度相等，但是即使是不区分大小写也不能使这两个字符串一致。比如 Beijing 和 Nanjing

编程判断输入的两个字符串之间的关系属于这四类中的哪一类，给出所属的类的编号。


Input
包括两行，每行都是一个字符串


Output
仅有一个数字，表明这两个字符串的关系编号


Sample Input 1

BEIjing
beiJing
Sample Output 1

3
 */
static void func1_18(string string1,string string2){

    if (string1.length()!=string2.length()){

        cout<<1;
    } else{
        for (int i = 0; i < string2.size(); ++i) {
            if (string2[i]>=string1[i]){

            } else{
                int key=string1[i];
                string1[i]=string2[i];
                string2[i]=key;
            }

            int k=string2[i]-string1[i];
            if (k!=0&&k!=32){
                cout<<4;
                break;
            } else{
                if (k==32){
                    cout<<3;
                    break;
                }
                if (i==string2.size()-1){cout<<2;};
            }
        }

    }
}
int main() {
    string string1;
    string string2;
    cin>>string1;
    cin>>string2;
    func1_18(string1,string2);
}
