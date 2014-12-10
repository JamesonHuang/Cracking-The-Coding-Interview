/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	                    （1）问题描述：
                            A.判断字符串中字符是否唯一
                            B.不使用额外数据结构（自定义数据结构）

    > Conclusion: 
                        （1）策略一：
                            A.根据字符的ASCII值进行排序
                        
                        （2）策略二：
                            A.定义bool类型数组，初始化置0
                            B.遍历字符串的每一字符
                            C.在数组相应位置，置1
                            D.如果出现对1置1的情况，返回false

	> Author:           rh_Jameson
	> Created Time:     2014年12月09日 星期二 10时53分06秒
 ************************************************************************/


#include<iostream>
#include "Solution.h"

/*
#include <vector>
#include <string>
#include <map>
#include <algorithm>
*/

using namespace std;

int main()
{
    Solution solution;
    //Test cases
    {
        string str = "abcdefg";
        cout << solution.Is_unique_str_bySort(str) << endl;
    }
    {
        string str = "abababab";
        cout << solution.Is_unique_str_bySort(str) << endl;
    }
    {
         string str = "";
        cout << solution.Is_unique_str_bySort(str) << endl;
    }
    return 0;
}
