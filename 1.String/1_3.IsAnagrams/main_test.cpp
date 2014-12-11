/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月10日 星期三 14时09分12秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include "Solution.h"

using namespace std;

int main()
{
    Solution solution;
    //Error test cases from leetcode.com
    //Test cases
    string strA, strB;   
    {
        strA = "abcd";
        strB = "dcb";
        cout << solution.IsAnagrams(strA,strB) << endl;
    }
 
    {
        strA = "abcd";
        strB = "dacb";
        cout << solution.IsAnagrams(strA, strB) << endl;
    }

    {
        strA = "baad";
        strB = "dbba";
        cout << solution.IsAnagrams(strA, strB) << endl;
    }

    {
        strA = "abcd";
        strB = "dcbA";
        cout << solution.IsAnagrams(strA, strB) << endl;
    }
    return 0;
}
