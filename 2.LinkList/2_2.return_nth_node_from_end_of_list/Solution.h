/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述：
                            A.单向链表
                            B.找到或者删除倒数第k个结点
	> Conclusion:        
                        （1）策略一：转成正数第m个
                            A.一轮遍历求链表长度
                            B.倒数第k个,即正数 m = n + 1 - k 个
                            C.遍历m个结点，返回第m个结点
                            
                        （2）策略二：快慢指针
                            A.快指针先走k步
                            B.接着快慢指针同时向前移动
                            C.直到链表遍历结束
                            D.返回慢指针指向的结点
                        
                        （3）边界测试用例：
                            A.空链表
                            B.k > n
                            C.k < 0
                            D.单结点链表

                        （4）传进来的头结点：
                            A.其实是第一个元素
                            B.最好自己新建个头结点
                            C.避免第一个结点特殊处理

                        （1）删除结点如果是head结点：
                            A.只能想到加个if
                            B.返回head->next
	
    > Author:           rh_Jameson
	> Created Time:     2014年12月16日 星期二 20时07分49秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include "LinkList.h"
using namespace std;

class Solution {
public:
//==================快慢指针实现====================//
    void getNthNode(ListNode *head,int k){
        if(head == NULL){
            cout << "空链表" << endl;
            return;
        }
        if(k <= 0){
            cout << "k值小于等于0，不合法" << endl;
            return;
        }
        ListNode *p_fast = new ListNode(0);
        p_fast->next = head;
        //
        for(int i = 0; i < k; i++){
            //处理k > len的情况
            if(p_fast == NULL){
                cout << "k大于链表长度！" << endl;
                return;
            }
            p_fast = p_fast->next;
        }
        ListNode *cur = new ListNode(0);
        cur->next = head;
        while(p_fast != NULL){
            p_fast = p_fast->next;
            cur = cur->next;
        }
        cout << "倒数第k个值是" << cur->val << endl;

    }
//================转换成正数第m个===================//
    void getNthNodeByM_th(ListNode *head,int k){
        if(head == NULL){
            cout << "空链表" << endl;
            return;
        }
        int len = 0;
        ListNode *cur = head;
        //求链表长度 
        while(cur != NULL){
            ++len;
            cout << len << "\t";
            cur = cur->next;
        }
        cout << endl;
        if(k > len || k < 1){
            cout << "k值不合法" << endl;
            return;
        }
        cout << endl;
        cout << head->val << endl; 
        cur = head;     //重置
        //遍历到第m个结点
        int m_th = len + 1 - k;
        for(int i = 1; i < m_th; ++i){
            cur = cur->next;
        }
        cout << "倒数第k个的值是" << cur->val << endl;
    } 
};

#endif
