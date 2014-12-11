/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月11日 星期四 15时06分23秒
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
    
    string str;
    {
        str = "aabcccccaaa";
        cout << solution.strCompression(str) << endl;
    }
    
    {
        str = "aabcccdeee";
        cout << solution.strCompression(str) << endl;
    }
    {
        str = "abcd";
        cout << solution.strCompression(str) << endl;
    }
    {
        str = "  aa  aa  aaaa  ";
        cout << solution.strCompression(str) << endl;
    }
    {
        str = "aabcccca";
        cout << solution.strCompression(str) << endl;
    }    
    {
        str = "aabccccaaa";
        cout << solution.strCompression(str) << endl;
    }
    {
        str = "cdeee";
        cout << solution.strCompression(str) << endl;
    }

    return 0;
}
