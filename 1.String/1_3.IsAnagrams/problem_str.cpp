/*************************************************************************
	> File Name:        problem_str.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月10日 星期三 15时07分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
//#include "Solution.h"

using namespace std;

int main()
{
    // Solution solution;
    //Error test cases from leetcode.com
    //Test cases
    
    string str = "abcd";
    for(int i = 0; i < str.size(); ++i){
        //cout << *(str + j) << " ";            //该方法报错
        cout << str[i] << " ";
    }
    cout << endl;
    
    char *ch_arr = "hello";
    for(int k = 0; k < strlen(ch_arr); k++){
        //cout << ch_arr[k] << " ";
        cout << *(ch_arr + k) << " ";
    } 
    int *int_arr = new int[10]();
    for(int i = 0; i < 10; ++i){
        cout << *(int_arr + i) << " ";
    }
    return 0;
}
