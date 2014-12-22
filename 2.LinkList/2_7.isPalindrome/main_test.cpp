/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月18日 星期四 17时51分38秒
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
    list->printLinkList(head->next);
    solution.isPalindrome(head->next);

    list->constructPalidromeList(head,7);
    list->printLinkList(head->next);
    solution.isPalindrome(head->next);

    return 0;
}
