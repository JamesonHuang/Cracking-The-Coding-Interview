/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月09日 星期二 16时59分41秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include "Solution.h"

#define MAXSIZE 100

using namespace std;

int main()
{
     Solution solution;
     //Error test cases from leetcode.com
     //Test cases
    {
        char str[] = "abcdefg";
        solution.reverse(str);
    }
    {
        char str[] = "";
        solution.reverse(str);
    }
    {
        char str[] = "   ab  b c   ";
        solution.reverse(str);
    }
    {
        char str[] = "  ";
        solution.reverse(str);
    }
    return 0;
}
