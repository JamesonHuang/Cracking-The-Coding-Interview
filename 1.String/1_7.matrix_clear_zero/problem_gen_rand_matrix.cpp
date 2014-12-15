/*************************************************************************
	> File Name:        problem_gen_rand_matrix.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月15日 星期一 09时56分07秒
 ************************************************************************/

#include <stdio.h>                     
#include <stdlib.h>                    
#include<ctime>
#include<vector>
#define M 10                           
#define N 10                           
using namespace std;                                               
int main(void)                         
{                                      
    int i = 0, j = 0;                  
    int Arr[M][N] = {{0}};             
    srand(time(NULL));                 
    vector<int> v;
    vector<vector<int> > arr_v;
    for (i = 0; i < M; ++i)            
    {                                  
        for (j = 0; j < N; ++j)        
        {                              
            Arr[i][j] = rand() % 1000;
            v.push_back(rand() % 1000);
        }                        
        arr_v.push_back(v);
    }                                  
                                               
    printf("Array[%d][%d] is: \n", M, N);
    for (i = 0; i < M; ++i)            
    {                                  
        for (j = 0; j < N; ++j)        
        {   
            printf("%d\t", arr_v[i][j]);
            //printf("%d\t", Arr[i][j]); 
        }                              
        printf("\n");                  
    }                                  
    return 0;                          
}
