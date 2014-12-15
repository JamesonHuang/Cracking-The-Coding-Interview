/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述
                            A.N * N矩阵表示图像
                            B.每像素4字节
                            C.实现图像旋转90度
                            D.不用额外空间
	> Conclusion:          
                        （1）策略一：四点轮换法
                            A.遍历行数N/2
                            B.将行中每个结点旋转到相应位置
                            C.通过tmp变量进行轮换
                            D.时间复杂度O（N^2）
                        
                        （2）策略二：对角线替换
                            A.交换对角线两边元素
                            B.对每一列元素进行逆置
                                a.逆时针旋转绕横轴
                                b.顺时针旋转绕纵轴
                            
                        （3）生成随机数
                            A.srand((int)time(NULL));
                            B.r = rand() % 10
                        
                        （4）传递二维数组参数
                            A.int a[10][10]
                            B.int a[][10]
                            C.不可以用二级指针
                                a.int** a;
                                b.相关网址：
                                    http://www.wutianqi.com/?p=1822
	
    > Author:           rh_Jameson
	> Created Time:     2014年12月14日 星期日 12时17分44秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    void printMatrix(const int n,int a[][7]){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

//=======================矩阵旋转：四点轮换法,Accepted=======================//
    //逆时针旋转90度
    void matrix_rotate_reverse(const int n, int a[][7]){
        if(n == 0){
            cout << "空矩阵" << endl;
        }
        int col = n, len = n;
        int midline = n / 2, tmp;
        
        for(int i = 0; i < midline; ++i){
            for(int j = i; j < col - 1 - i; ++j){
                tmp = a[j][i];
                a[j][i] = a[i][len - 1 - j];
                a[i][len -1 -j] = a[len - 1 - j][len - 1 - i];
                a[len - 1 - j][len - 1 - i] = a[len - 1 - i][j];
                a[len - 1 - i][j] = tmp;
            }
        }
        printMatrix(n, a);
    }

    //顺时针旋转90度
    void matrix_rotateByExchg(const int n, int a[][7]){
        if(n == 0){
            cout << "空矩阵" << endl;
        }
        int col = n, len = n;
        int midline = n / 2, tmp;
        
        for(int i = 0; i < midline; ++i){
            for(int j = i; j < col - 1 - i; ++j){
                tmp = a[i][j];
                a[i][j] = a[len - 1 - j][i];
                a[len - 1- j][i] = a[len - 1 - i][len - 1 - j];
                a[len - 1 - i][len - 1 - j] = a[j][len - 1 - i];
                a[j][len - 1 - i] = tmp;
            }
        }
        printMatrix(n, a);
    }

//=====================矩阵旋转：对角线替换,Accepted======================//
    void swap(int &a, int &b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    
    
    void matrix_rotate(const int n, int a[][7]){
        int len = n;
        //对角线两侧元素互换
        for(int i = 0; i < len; ++i){
            for(int j = i; j < len; ++j){
                swap(a[i][j],a[j][i]);
            }
        }
        //根据纵轴逆置元素
        for(int line = 0; line < len; ++line){
            for(int first = 0,last = len - 1; first < last; ++first, --last){
                swap(a[line][first],a[line][last]);
            }
        }
        printMatrix(n, a);
    }

};

#endif
