/*************************************************************************
	> File Name:        Solution.h
	> Description:     
                        （1）问题描述：
                            A.翻转一个NULL结尾的字符串
                            B."abcd" => "dcba"
	> Conclusion:          
                        （1）策略一：首尾索引交换
                            A.遍历字符获得尾下标
                            B.首尾两两交换
                        
                        （2）策略二：单索引法
                            A.strlen()获取长度 再模2，赋给mid
                            B.遍历[0,mid)
                            C.swap(i,n - i - 1)

                        （3）交换变量的方法：
                            A.求和交换
                            B.抑或交换
                                a.简洁美观，无需临时变量
                                b.编译效率无提升
                                c.swap同一引用变量时，有bug
                                d.swap(a, a) => a变为0
                            C.临时变量交换

                        （4）空字符串处理：
                            A. *str == "" or str == NULL or !str都不行
                            B. 因为str本身有值，是一个内存地址
                            C. 改为：str[0] == '\0' / NULL  或 !str[0]
                        
                        （5）结束函数：
                            A.return;
                            B.exit();
                            C.某些平台下，return无法结束

	> Author:           rh_Jameson
	> Created Time:     2014年12月09日 星期二 17时00分06秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

class Solution {
public:
    void reverseBy2Index(char* str);            //g++下传入只能是char[],而不能是char*
    void reverse(char* str);
    //通过抑或交换
    void swapByXor(char &a, char &b);
    //通过求和交换
    void swapBySum(char &a, char &b);
    //通过临时变量交换
    void swapByTmp(char &a, char &b);
};
/*
 * 省去临时变量，简洁美观，但效率木有提升
 * swap（a，a）交换同一引用变量会出现bug
 * 交换完，a变为0
 */
void Solution::swapByXor(char &a, char &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


void Solution::swapBySum(char &a, char &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void Solution::swapByTmp(char &a ,char &b){
    char tmp = a;
    a = b;
    b = tmp;
}

//===========================一个指针版本=============================//
void Solution::reverse(char* str){
    //空字符串处理
    if(!str[0]){
        cout << "空字符串！" << endl;
        return;
    }
    int len = strlen(str);
    int mid = len / 2;
    for(int i = 0; i < mid; ++i){
        swapBySum(str[i],str[len - i - 1]);     //i 与 len - i - 1对应
    } 
    cout << str << endl;
}

//============================首尾指针交换版=========================//
void Solution::reverseBy2Index(char* str){
    /*
     *空字符数组判空：
     *str == "" or str == NULL or !str都不行
     *因为str本身有值，是一个内存地址
     *改为：str[0] == '\0' / NULL  或 !str[0]
     */
    //空字符串处理
    if(!str[0]){
        cout << "空字符串！" << endl;
        return;
    }

    int last = 0;
    //遍历获取尾元素下标
    while(str[last] != '\0'){
        ++last;
    }
    --last;    //移去null结尾的字符
    
    int first = 0;
    int tmp;
    //反转
    while(first < last){
        //swapByXor(str[first++], str[last--]);
        swapBySum(str[first++], str[last--]);
        //swapByTmp(str[first++], str[last--]);
    }
    cout << str << endl;
}

#endif
