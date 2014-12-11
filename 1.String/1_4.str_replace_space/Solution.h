/**********************************************************************************
	> File Name:        Solution.h
	> Description:     
                        (1)问题描述：
                            A.将字符串中的所有空格替换为%20
                            B.前提：首尾空格去除
                            C.不用额外空间
	> Conclusion:
                        (1)策略一：空格替换 & 移位
                            A.去除首尾空格 & 判空
                            B.遍历空格数目
                            C.重置字符串的大小，以及首尾iterator
                            D.遍历移位 & 替换
                        
                        (2)策略二：使用STL的replace方法
                            A.去除首尾空格 & 判空
                            B.遍历替换replace（pos, num, obj）
                        
                        (3)消除首尾空格关键代码：
                            A. s.erase(0, s.find_first_not_of(' '))
                            B. s.erase(s.find_last_not_of(' ') + 1, s.size() - 1); 
                            C.不能写成erase（s.begin(),s.find_first_not_of(' ')） 
                            D.find_first_not_of()返回类型为：size_t,而非iterator                        
                            E.find_last_not_of同样遵循C，D

                        (4)resize（）原型：
                            A.s.resize(size, "c")
                            B.例：s = "abc"; s.resiz(5,"d") ==> s = "abcdd" 

	> Author:           rh_Jameson
	> Created Time:     2014年12月11日 星期四 09时26分22秒
 **********************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:

//=====================使用stl中的相关方法========================//
    string replace_space(string s){
        if(s[0] == ' '){
            s.erase(0, s.find_first_not_of(' '));
        }
        if(s[s.size() - 1] == ' '){
            s.erase(s.find_last_not_of(' ') + 1, s.size() - 1);
        }
        int len = s.size();
        for(int i = 1; i < len; ++i){
            if(s[i] == ' '){
                s.replace(i,1,"%20");
            }
        }
        return s;
    }
     
//========================空格替换 & 移位========================//
    string replace_spaceOrigin(string s){
        string::iterator first_iter = s.begin();
        string::iterator last_iter = s.end() - 1;
        //消除首尾空格
        if(*first_iter == ' '){
            //不能写成erase（s.begin(),s.find_first_not_of(' ')）
            s.erase(0, s.find_first_not_of(' '));          //改' '
        }
        if(*last_iter == ' '){
            s.erase(s.find_last_not_of(' ') + 1, s.size() - 1);
        }
        //先消除首尾空格，再判空
        if(s.empty()){
            cout << "空串或无实际意义的串" << endl;
            return s;
        }
        //遍历获得空格数目
        int blank_cnt = 0;
        for(string::iterator i = s.begin(); i < s.end(); ++i){
            if(*i == ' '){
                blank_cnt++;
            }
        }
        //计算移动几位
        int mov_cnt = blank_cnt * 2;
        //重置s的大小
        s.resize(s.size() + mov_cnt,'=');       //resize（size_value, fill_char）
        last_iter = s.end() - mov_cnt - 1;      //s中最后一个有意义的字符
        first_iter = s.begin(); 
        //s[s.size() + mov_cnt] = '\0';
        //遍历移位
        for(string::iterator i = last_iter; i >= first_iter; --i){
            if(*i == ' '){                      //替换空格
                *(i + mov_cnt) = '0';
                *(i + mov_cnt - 1) = '2';
                *(i + mov_cnt - 2) = '%';
                mov_cnt -= 2;
            }
            else{
                *(i + mov_cnt) = *i;            //移位赋值
            }
        }
        return s;
    }
};

#endif
