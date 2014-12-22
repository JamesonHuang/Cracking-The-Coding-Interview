/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述：
                            A.检测链表是否为回文
	
    > Conclusion:      
                        （1）策略一：数组保存原链表
                            A.逆置链表
                            B.同时将结点存入数组
                            C.遍历新链表
                            D.同时与数组相应位置比较
                            E.相等移入下一位置
                            F.不等返回false

                        （2）策略二：快慢指针实现
                            A.快慢指针进行一轮遍历
                            B.慢指针将链表分段
                            C.对前半段进行反转
                            D. 遍历判断前后两段元素是否相等

                        （3）策略二优化：
                            A.慢指针边移动时，边反转元素
                            B.代码搅在一起也不是一件好事
                            C.代码出错率增加
    
	> Author:           rh_Jameson
	> Created Time:     2014年12月18日 星期四 17时52分27秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include "LinkList.h"

using namespace std;

class Solution {
public:
//==========================优化（有潜在边界问题）：不使用使用额外数组判断回文======================//
    void isPalindrome(ListNode *head){
        if(head == NULL){
            cout << "NULL LinkList!" << endl;
            return;
        }
        if(head->next == NULL){
            cout << "single node LinkList!" << endl;
            return;
        }
        if(head->next->next == NULL){
            if(head->val != head->next->val){
                cout << "it is not a Palindrome" << endl;
                return;
            }
            else{
                cout << "it is a Palindrome" << endl;
                return;
            }
        }
        //快慢指针遍历链表，同时反转p_slow前面的结点
        ListNode *p_slow = head, *p_fast = head->next;
        ListNode *pre = NULL, *cur = head, *p_next; 
        while(p_fast != NULL){              
            p_slow = p_slow->next;
            p_fast = p_fast->next->next; 

            p_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = p_next;
            if(p_fast->next == NULL){
                p_next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = p_next;
                break;
            }
        }
        //链表长度为奇数的话，cur要向前移动一位
        if(p_fast == NULL){
            cur = cur->next;
        }
        //判断两段链表相应结点值是否相等
        while(pre != NULL){
            if(pre->val != cur->val){
                cout << "it is not a Palindrome" << endl;
                return;
            }
            pre = pre->next;
            cur = cur->next;
        }
        cout << "it is a Palindrome" << endl;
         
    }

//==========================不使用额外数组判断回文======================//
    void isPalindromeByPtr(ListNode *head){
        if(head == NULL){
            cout << "NULL LinkList!" << endl;
            return;
        }
        if(head->next == NULL){
            cout << "single node LinkList!" << endl;
            return;
        }
        //快慢指针遍历链表
        ListNode *p_slow = head, *p_fast = head->next;
        while(p_fast->next != NULL && p_fast->next->next != NULL){              //->next->next 这里发生段错误，需加入前半段才行
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;
        }
        //反转p_slow前半段结点
        ListNode *pre = NULL, *cur = head, *p_next;
        while(pre != p_slow){
            p_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = p_next;
        }
        //链表长度为奇数的话，cur要向前移动一位
        if(p_fast->next != NULL){
            cur = cur->next;
        }
        //判断两段链表相应结点值是否相等
        while(pre != NULL){
            if(pre->val != cur->val){
                cout << "it is not a Palindrome" << endl;
                return;
            }
            pre = pre->next;
            cur = cur->next;
        }
        cout << "it is a Palindrome" << endl;
        
    } 
    
    
//==========================使用额外数组存放原顺序======================//
    void isPalindromeByArray(ListNode *head){
        if(head == NULL){
            cout << "空链表" << endl;
            return;
        }
        if(head->next == NULL){
            cout << "单结点链表：" << head->val << endl;
            return;
        }
        vector<int> vec_pal;
        ListNode *pre = NULL, *cur = head, *p_next;
        while(cur != NULL){
            vec_pal.push_back(cur->val);
            p_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = p_next;
        }
        head = pre;
        cur = pre;
        for(vector<int>::iterator i = vec_pal.begin(); i < vec_pal.end();++i){
            if(*i != cur->val){
                cout << "不是回文" << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "是回文链表！" << endl;


    }
};

#endif
