/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月16日 星期二 20时03分32秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include "Solution.h"
#include "LinkList.h"
using namespace std;

int main()
{
     Solution solution;
     //Error test cases from leetcode.com
     //Test cases
    
    Linklist *list = new Linklist();
    
    ListNode *head =new ListNode(0);
    list->constructLinkList(head);
    list->printLinkList(head);
    
    int k = 4;
    solution.getNthNode(head,k);

    return 0;
}
