/*************************************************************************
	> File Name:        Solution.h
	> Description:     
                        （1）问题描述：
                            A.判断两个字符串是否是变位词
                            B.变位词定义：
                                a,单词字符，出现次数相同
                                b.位置不同
                            C."abcd" & "bcda" => true
	> Conclusion:                
                        （1）策略一（Wrong）：Bool数组
                            A.遍历strFrom每个字符
                            B.在Bool数组相应位置置1
                            C.遍历strTo每个字符
                            D.判断每个字符在bool数组中是否置1
                            E.不是，返回false
                            F.错误原因：为考虑重复元素，
                            G.如：baad & abbd => false

                        （2）策略二：int数组
                            A.思路同一
                            B.一起遍历strFrom，strTo
                            C.每个字符，strFrom操作 + 1，strTp - 1
                            D.遍历int数组，如果为0，就返回true
                            E.最后一轮遍历费时间，如果是Unicode的话

                        （3）策略三：排序
                            A.strFrom跟strTo分别排序
                            B.再来一轮遍历，比较两者是否一样

                        （4）策略三：int数组2
                            A.遍历strFrom
                            B.strFrom每个字符，在int数组相应位置 + 1
                            C.遍历strTo
                            D.strTo每个字符，在int数组相应位置 - 1
                            E.- 1后，判断值是否小于0，小于则返回false

                        （5）STL sort()
                            A.sort(begin,end)

                        （6）C++强制转换方法：
                            A.static_cast<int>(obj);

                        （7）C++的string与char*的不同：
                            A.string不能用指针访问
                                a.*(str + i)，该访问方式报错
                                b.只能如此访问str[i]
                            B.char*两种方式都行:
                                a.str[i] & *(str + i)

    > Author:           rh_Jameson
	> Created Time:     2014年12月10日 星期三 14时16分09秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

class Solution {
public:
    bool IsAnagramsOrigin(string strFrom,string strTo);
    bool IsAnagrams(string strFrom,string strTo);
    bool IsAnagramsByIntArray(string strFrom,string strTo);
    bool IsAnagramsBySort(string strFrom,string strTo);
    
};


//=============int数组优化版：Correct，空间开销适度=================//
bool Solution::IsAnagrams(string strFrom, string strTo){

    if(strFrom.size() != strTo.size()){
        return false;
    }

    int *flag = new int[256]();    
    //有些编译器对动态数组不会自动初始化，需手动置0
    memset(flag, 0, sizeof(*flag));
    int len = strFrom.size();
    int index;
    for(int i = 0; i < len; ++i){
        index = static_cast<int>(strFrom[i]);       //改c++强制转换 

        *(flag + index) += 1;
    }
    for(int i = 0; i< len; ++i){
        index = static_cast<int>(strTo[i]);
        *(flag + index) -= 1;
        if(*(flag + index) < 0 ){         
            return false;
        }
    }
    return true;
}


//===================排序版：时间nlogn，无需额外空间===================//
bool Solution::IsAnagramsBySort(string strFrom,string strTo){
    if(strFrom.size() != strTo.size()){
        return false;
    }
    sort( &strFrom[0], &strFrom[0] + strFrom.size() );
    sort( &strTo[0], &strTo[0] + strTo.size() );
    if(strFrom == strTo){
        return true;
    }
    else{
        return false;
    }
}



//==================int数组版：Correct，空间开销大=====================//
bool Solution::IsAnagramsByIntArray(string strFrom, string strTo){

    if(strFrom.size() != strTo.size()){
        return false;
    }

    int *flag = new int[256]();    
    //有些编译器对动态数组不会自动初始化，需手动置0
    memset(flag, 0, sizeof(*flag));
    int len = strFrom.size();
    int index,index2;
    for(int i = 0; i < len; ++i){
        index = static_cast<int>(strFrom[i]);       //改c++强制转换 
        index2 = static_cast<int>(strTo[i]);       

        *(flag + index) += 1;
        *(flag + index2) -= 1;
    }
    for(int i = 0; i< 256; ++i){
        if(*(flag + i) != 0 ){          //数组全为0，则两者是变位词
            return false;
        }
    }
    return true;
}
//===================bool数组原始版：忽略重复元素，Wrong！==================//
bool Solution::IsAnagramsOrigin(string strFrom, string strTo){

    if(strFrom.size() != strTo.size()){
        return false;
    }

    bool *flag = new bool[256]();    
    //有些编译器对动态数组不会自动初始化，需手动置0
    memset(flag, 0, sizeof(*flag));
    int len = strFrom.size();
    int index;
    for(int i = 0; i < len; ++i){
        //int index = (int) ( *(strFrom + i) );    //与char*不同，string中无法通过*(str + i)来访问      
        index = (int) strFrom[i];                  //改c++强制转换 
        *(flag + index) = true;
    }
    for(int i = 0; i< len; ++i){
        index = (int) strTo[i];
        if(*(flag + index) != true){
            return false;
        }
    }
    return true;
}



#endif
