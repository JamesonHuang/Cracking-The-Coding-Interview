/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
                        （1）问题描述
                            A.N * N矩阵表示图像
                            B.每像素4字节
                            C.实现图像旋转90度
                            D.不用额外空间
	> Conclusion:          
                        （1）策略一：四点替换
                            A.遍历行数N/2
                            B.将行中每个结点旋转到相应位置
                            C.通过tmp变量进行轮换
                            D.时间复杂度O（N^2）
                        
                        （2）策略二：对角线替换
                            A.交换对角线两边元素
                            B.对每一列元素进行逆置
                            
                        （3）生成随机数
                        （4）传递二维数组参数

    > Author:           rh_Jameson
	> Created Time:     2014年12月14日 星期日 12时18分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<ctime>

#include "Solution.h"

using namespace std;

int main()
{
     Solution solution;
     //Error test cases from leetcode.com
     //Test cases
    
    /*test rand()
        srand((int) time(NULL));
        for(int i = 0; i < 10; ++i){
            cout << rand() % 100 << endl;
        }
    */
    srand( (int)time(NULL) );
    {
        cout << "========================================" << endl;
        const int n =  7;
        int  a[n][n];
        //矩阵随机赋值,并打印
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                a[i][j] = rand() % 10;
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        solution.matrix_rotate(n, a);
    }
    {
        cout << "========================================" << endl;
        const int n = 7;
        int a[n][n];
        //矩阵随机赋值,并打印
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                a[i][j] = rand() % 10;
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        solution.matrix_rotate(n, a);
    }
   
    
    {
        cout << "========================================" << endl;
        const int n = 7;
        int a[n][n];
        //矩阵随机赋值,并打印
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                a[i][j] = rand() % 10;
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        //solution.matrix_rotate(n,a);
        solution.matrix_rotate(n, a);
    }
   
   
   
    return 0;
}
