/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月11日 星期四 09时17分14秒
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
        str = "Mr John Smith";
        //str.resize(100);
        cout << solution.replace_space(str) << endl;
    }
    
    {
        str = "hello world i am back ";
        //str.resize(100);
        cout << solution.replace_space(str) << endl;
    }{
        str = " talyer   swift  ";
        //str.resize(100);
        cout << solution.replace_space(str) << endl;
    }{
        str = "  Mr John Smith  ";
        //str.resize(100);
        cout << solution.replace_space(str) << endl;
    }
    
    {
        str = "";
        cout << solution.replace_space(str) << endl;
    }  
    
    {
        str = "  ";
        cout << solution.replace_space(str) << endl;
    }
    return 0;
}
