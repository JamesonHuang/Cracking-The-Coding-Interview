/********************************************************************************
    > File Name:         Solution.h
	> Description:     
                        （1）问题描述：
                            A.字符串压缩
                            B.将重复出现的字符转成数字形式
                            C."aabcccccaaa" ==> "a2b1c5a3"
	> Conclusion:          
                        （1）策略一：原字符串操作法
                            A.不用额外空间
                            B.去除空格
                            C.判空
                            D.字符压缩
                                a.快慢索引指向值相等，cnt++，快索引向前移位
                                b.不等，则判断cnt是否等于1
                                c.cnt == 1
                                    *.慢索引向前移动一步
                                    *.将快索引的值赋给慢索引的值
                                    *.在慢索引处insert "1"
                                    *.快索引向前移动一位
                                d.cnt != 1
                                    *.将cnt转成字符串并替换到慢索引的下一位置
                                    *.cnt置1
                            E.最后一组重复字符的处理

                        （2）策略二：另开一字符串
                            A.去处空格 & 判空
                            B.字符压缩
                                a.快慢索引指向值相等，cnt++，快索引向前移位
                                b.不等，新字符串插入慢索引指向字符和cnt值
                                c.慢索引指向快索引指向值，cnt置1
                            C.最后一组重复字符的处理，同B，但仅作一次
                        
                        （3）itoa相关：
                            A.定义： 整型数值转为字符串
                            B.例： int n = 10；==》"10"
                            C.itoa函数
                                a.所属头文件<cstdlib>
                                b.原型：itoa（int_value,string_buf,base）
                                    *.base:进制,可选2,8,10,16
                                c.linux下不可用
                            D.linux下如何使用itoa
                                a.自己写一个
                                b.用stringstream
                                    *.stringstream ss << int_value
                                    *.ss >> str
                                c.c++ 11提供：
                                    string s = std::to_string(int_value);
                                d.

                        （4）字符串连接函数append()：
                            A.strComp.append(s, idx, 1);
                            B.strComp.append(s);
                            C.参见cplusplus.com
                        
    > Author:           rh_Jameson
	> Created Time:     2014年12月11日 星期四 15时10分23秒
 ***********************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cstdlib>

using namespace std;

class Solution {
public:

    //int转string
    string itoa(int n){
        stringstream ss;
        ss << n;
        string tmp;
        ss >> tmp;
        
        /*linux下没有itoa函数
        string tmp;
        itoa(cnt, tmp, 10);
        */
        
        //c++11才可以用
        //string tmp = std::to_string(cnt);
        
        return tmp;
    }
    //消除空格
    void removeStrSpace(string &s){
        
        string::iterator iter = s.begin();
        string::iterator end = s.end();
        
        while(iter < end){
            if(*iter == ' '){
                s.erase(iter);
            }
            else{
                ++iter;
            }
        }  
    }
//=======================不用额外字符串版本=====================//
    //字符串压缩
    string strCompressionBetter(string s){
        //消除空格
         removeStrSpace(s);
        //判空 
        if(s.empty()){                     
            cout << "空字符串" << endl;
        }
        //字符压缩
        int cnt = 1, idx = 0, i;
        string tmp;                    
        for(i = 1; i < s.size(); ++i){           
            if(s[idx] == s[i]){
                cnt++;
            }
            else{
                if(cnt != 1){
                    tmp = itoa(cnt);
                    s.replace(++idx,1,tmp);
                    s[++idx] = s[i];
                    cnt = 1;
                }
                else{
                    s[++idx] = s[i];
                    s.insert(idx++,"1");
                    i++;
                }
            }
        }
        //最后的判断 & 处理
        if(cnt == 1){
            s[++idx] = s[i];
            s.insert(idx++,"1");
        }
        if(cnt != 1){
            tmp =itoa(cnt);
            s.replace(++idx,1,tmp);
            s[++idx] = s[i];
        }
        s.resize(idx);
        return s;
    }
//======================另开字符串版本====================//
    //字符串压缩
    string strCompression(string s){
        //消除空格
        removeStrSpace(s);
        //判空
        if(s.empty()){
            cout << "空字符串" << endl;
        }
        //字符压缩
        string strComp,tmp;
        int idx = 0, i, cnt = 1, len = s.size();
        /*快慢下标，相等，cnt++
         * 不等，将s[idx]和cnt插入strComp中
         */
        for(i = 1; i < s.size(); ++i){
            if(s[idx] == s[i]){
                cnt++;
            }
            else{
                strComp.append(s, idx, 1);
                tmp = itoa(cnt);
                strComp.append(tmp);
                //idx += cnt;
                idx = i;
                cnt = 1;
            }
        }
        //最后重复一次处理
        strComp.append(s, idx, 1);
        tmp = itoa(cnt);
        strComp.append(tmp);

        return strComp;
    }
};

#endif
