/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月14日 星期日 22时24分02秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<ctime>
#include "Solution.h"
#include<unistd.h>              //include sleep()
using namespace std;

int main()
{
     Solution solution;
     //Error test cases from leetcode.com
     //Test cases
     /*{
        srand( (int)time(NULL) );
        int cols = rand() % 10 + 1;
        int lines = rand() % 10 + 1;
        int tmp;
        vector< vector<int> > matrix;
        vector<int> line_element;
        for(int j = 0; j < lines; ++j){
            for(int i = 0; i < cols; ++i){
                tmp = rand() % 10;
                line_element.push_back(tmp);
                cout << line_element[i] << " ";
                //sleep(1);
            }
            cout << endl;
            matrix.push_back(line_element);
        }
     }*/
/*
   {
        srand( (int)time(NULL) );
        const int cols = 4;
        //const int lines = rand() % 10 + 6;
        const int lines = 5;
        int a[lines][cols];
        for(int j = 0; j < lines; ++j){
            for(int i = 0; i < cols; ++i){
                a[j][i] = rand() % 10;
                cout << a[j][i] << " ";
            }
            cout << endl;
        }
        cout << "==========================" << endl; 
        solution.setZeroes(a);

    }*/
   {
        srand( (int)time(NULL) );
        const int cols = 2;
        //const int lines = rand() % 10 + 6;
        const int lines = 1;
        int a[lines][cols] = {0,1};
        for(int j = 0; j < lines; ++j){
            for(int i = 0; i < cols; ++i){
                cout << a[j][i] << " ";
            }
            cout << endl;
        }

        cout << "==========================" << endl; 
        solution.setZeroes(a);

    }
    return 0;
}
