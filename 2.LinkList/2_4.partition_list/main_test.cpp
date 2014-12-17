/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月17日 星期三 14时09分40秒
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
    ListNode *head = new ListNode(0);
    
    list->constructLinkList(head);
    list->printLinkList(head);
    
    solution.partition(head, 50);
    list->printLinkList(head);

    return 0;
}
