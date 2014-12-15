/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述：
                            A.M * N矩阵
                            B.若某个元素为0，所在行与列均清零
	> Conclusion:
                        （1）策略一：哈希表保存清零的行与列
                            A.遍历矩阵
                            B.用map记录元素为0的行, 列
                            C.对相应行清零
                            D.相应列清零

                        （2）策略二：复用0行0列记录要清零的行，列
                            A.不用额外空间，直接复用0行0列的空间
                            B.判断0行跟0列是否存在0，bool标志真/假
                            C.遍历其余行跟列
                            D.元素为0的行列，存到0行0列的相应位置
                            E.遍历清零
                            F.检测bool标志，判断0行0列是否存在0
                            G.存在，则对0行 / 0列清零

                        （3）vector<vector<int> > m：
                            A.相当于二维数组 m[i][j]
                            B.行数：m.size()
                            C.列数：m[0].size()
                            D.m[i][j]形式，通过2个for循环可生成随机矩阵
                            E.vector形式不能生成
                            F.http://blog.csdn.net/qingdujun/article/details/17499871

                        （4）map & hashtable：
                            A.C++ STL严格来说没有实现哈希表结构
                            B.map底层是红黑树，访问复杂度为logN
                            C.哈希表一般是常数时间访问
                            D.性能：unordered_map > hash_map > map
                            E.需要有序关联容器的话要用map
                            F.http://blog.chinaunix.net/uid-20384806-id-3055333.html
                            G.http://yiluohuanghun.blog.51cto.com/3407300/1086355
                            H.http://blog.csdn.net/peter_teng/article/details/8433395
                            I.http://www.cnblogs.com/waytofall/archive/2012/06/04/2534386.html
	> Author:           rh_Jameson
	> Created Time:     2014年12月14日 星期日 22时24分29秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
//#include<hash_map>
using namespace std;

class Solution {
public:

    void printMatrix(int matrix[1][2]){
        int col_num = 2;
        int line_num = 1;
        for(int i = 0; i < line_num; ++i){
            for(int j = 0; j < col_num; ++j){
                cout << matrix[i][j] << " "; 
            }
            cout << endl;
        }
        cout << endl;
    }
//=====================map保存要清0的行与列：Accepted=====================//‘
    
    void setZeroesByHash(int matrix[5][4]) {
        int col_num = 4;
        int line_num = 5;
        map<int, int> col_map, line_map;            //记录清零的行与列
        int col_zero = 0, line_zero = 0;            //清零行，列的个数
        //遍历记录清零的行与列
        for(int i = 0; i < line_num; ++i){
            for(int j = 0; j < col_num; ++j){
                if(matrix[i][j] == 0){
                    line_map[++line_zero] = i;
                    col_map[++col_zero] = j;
                }
            }
        }
        int tmp;
        //所在行清零
        while(line_zero > 0){
            tmp = line_map[line_zero];
            for(int i = 0; i < col_num; ++i){
                matrix[tmp][i] = 0;
            }
            --line_zero;
        }
        printMatrix(matrix);
        //所在列清零
        while(col_zero > 0){
            tmp = col_map[col_zero];
            for(int i = 0; i < line_num; ++i){
                matrix[i][tmp] = 0;
            }
            --col_zero;
        }
        printMatrix(matrix); 
        
    }


//=====================不用额外空间实现：Accepted=====================//
    
    void setZeroes(int matrix[1][2]) {
        int col_num = 2;
        int line_num = 1;
        bool flag_line = false,flag_col = false;
        //判断第零行是否有0
        for(int i = 0; i < col_num; ++i){
            if(matrix[0][i] == 0){
                flag_line = true;
                break;
            }
        }
        //判断第零列是否有0
        for(int i = 0; i < line_num; ++i){
            if(matrix[i][0] == 0){
                flag_col = true;
                break;
            }
        }
        //将出现0的行，列记录到第0行和第零列上
        for(int i = 1; i < line_num; ++i){
            for(int j = 1; j < col_num; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //清零
        for(int i = 1; i < line_num; ++i){
            for(int j = 1; j < col_num; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //判断第零行,第零列是否要清零
        if(flag_line){
            for(int i = 0; i < col_num; ++i){
                matrix[0][i] = 0;
            }
        }
        if(flag_col){
            for(int i = 0; i < line_num; ++i){
                matrix[i][0] = 0;
            }
        }
        printMatrix(matrix);    
    }
};

#endif
