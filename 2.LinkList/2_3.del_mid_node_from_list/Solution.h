/*************************************************************************
	> File Name:        Solution.h
	> Description:     
                        （1）问题描述:
                            A.单向链表
                            B.只能访问某结点
                            C.且该结点要被移除
	
    > Conclusion:          
                        （1）策略:
                            A.将该结点的下一个结点拷贝到该结点上
                            B.注意边界

                        （2）边界测试用例:
                            A.空链表
                            B.单结点链表
                            C.要删除结点是最后一个结点
                        

    > Author:           rh_Jameson
	> Created Time:     2014年12月16日 星期二 21时58分22秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>

#include"LinkList.h"

using namespace std;

class Solution {
public:
    void removeMidNode(ListNode *midNode){
        if(midNode == NULL || midNode->next == NULL){
            cout << "输入不合法" << endl;
        }
        *(midNode) = *(midNode->next);
        //midNode->val = midNode->next->val;
        //midNode->next = midNode->next->next;
    }
};

#endif
