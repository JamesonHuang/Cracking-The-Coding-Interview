/*************************************************************************
	> File Name:        Solution.h
	> Description:      
	                    （1）问题描述：
                            A.判断字符串中字符是否唯一
                            B.不使用额外数据结构（自定义数据结构）

    > Conclusion: 
                        （1）策略一：
                            A.根据字符的ASCII值进行排序
                            B.相邻索引比较
                        
                        （2）策略二：
                            A.定义bool类型数组，初始化置0
                            B.遍历字符串的每一字符
                            C.在数组相应位置，置1
                            D.如果出现对1置1的情况，返回false
                        
                        （3）策略三：
                            A.思路同二，换成位操作
                            B.bool数组换成int bit[8]
                                a.int ==> 32位
                                b.8 * 32 = 256
                            C.str[i] / 32获取数组下标
                            D.str[i] % 32获取偏移量
                        
                        （4）相关头文件
                            A.memset() ==> <cstring> / <string.h>
                                a.原型：memset（void *s int ch, size_t n）
                                b.例：  memset(bit, 0, sizeof(bit))
                            B.calloc() ==> <cstdlib>
                                a.例：
                                    (bool *)calloc(256, sizeof(bool));
                            C.malloc() ==  <cstdlib>

                        (5) 三整数a,b,c排序：
                            A.judge a > b,  y==>swap()
                            B.judge a > c,  y==>swap()
                            C.judge b > c,  y==>swap()

                        (6)判断字符串是否为空的方法：
                            A.s.empty()
                            B.s == ""
                            C.s.length() / s.size() == 0
                        
                        (7)动态数组初始化：
                            A.g++编译器会自动初始化为0或NULL
                            B.其他变一起可能不会，需memset()


	> Author:           rh_Jameson
	> Created Time:     2014年12月09日 星期二 10时49分53秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include<cstring>           //memset
#include<cstdlib>           //calloc/malloc

using namespace std;
class Solution {
public:
//================Bool数组位操作版===============//
    bool Is_unique_str(string &s){
        if(s.empty()){                  //判空
            return true;
        }

        int bit[8];                     //8个整形变量，共256位
        memset(bit, 0, sizeof(bit));    
        for(string::iterator i = s.begin(); i < s.end(); ++i){
            int index = (int) *i / 32;  //获取相应数组下标
            int shift = (int) *i % 32;  //获取相应偏移位数
            
            if(bit[index] & 1 << shift){
                return false;
            }
            bit[index] |= 1<< shift;
        }
        return true;
    }

//================Bool数组STL形式版===============//
    bool Is_unique_strSTL(string &s){
        if(s.empty())
        {
            return true;
        }
        //memset置0
        //bool flag[256];
        //memset(flag,0,sizeof(flag));
        
        //calloc置0
        //bool* flag = (bool *)calloc(256, sizeof(bool));
       
        //new,自动初始化置0，但有些编译器不自动初始化
        bool* flag = new bool[256];
        //bool* flag = new bool[256]();
        
        for(string::iterator i = s.begin(); i < s.end(); ++i){
            int tmp = (int) *i; 
            if(flag[tmp] == 0){
                flag[tmp] = 1;
            }
            else{
                return false;
            }
        }
        delete[] flag;
        return true;
    }
//=====================Bool数组原始版=========================//
    bool Is_unique_strOrigin(string &s){
        if(s.empty())
        {
            return true;
        }
        bool flag[256];
        memset(flag,0,sizeof(flag));
        int len = s.size();
        for(int i = 0; i < len; ++i){
            int tmp = (int)s[i]; 
            if(flag[tmp] == 0){
                flag[tmp] = 1;
            }
            else{
                return false;
            }
        }
        return true;
    }

//================字符排序版（nlogn）==================//
    bool Is_unique_str_bySort(string &s){
        if(s.empty()){
            return true;
        }
        sort(&s[0],&s[0] + s.size());
        int index = 0;
        int len = s.size();
        for(int i = 1; i < len; ++i){
            if(s[index] == s[i]){
                return false;
            }
            index++;
        }
        return true;
    }    
};


#endif
