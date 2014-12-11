/*************************************************************************
	> File Name:        Solution.h
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月11日 星期四 15时10分23秒
 ************************************************************************/

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
