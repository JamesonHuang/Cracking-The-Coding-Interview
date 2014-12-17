/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                       （1）问题描述：
                            A.链表分割成两部分
                            B.以给定值x为基准
                            C.小于x的结点在前
                            D. 大于或等于x的结点在后
	> Conclusion:       
                       （1）策略一：另开链表
                            A.新建一链表
                            B.小于x，从原链表中删除
                            C.并将其插入新建链表中
                            D. 结束一轮遍历后，连接两条链表

                       （2）策略二：头插处理
                            A.遍历链表
                            B.比x小的结点，从链表中删除
                            C.再用头插法插入链表
    
                       （3）关于策略二：
                            A.leetcode上不能使用头插法
                            B.书上也木有相似解法
                            C.原因：头插法顺序变化了
                            D.但题目没说要按原顺序啊～～ 
	
                       （4）头结点（指第一个元素）改变的情况：
                            A.需改为指针的引用ListNode* &node 
                            B.第一个元素往往要特殊对待
    
    > Author:           rh_Jameson
	> Created Time:     2014年12月17日 星期三 13时40分42秒
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
//=====================另开一个链表======================//
    ListNode *partitionByNewList(ListNode *head, int x) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        //指针太多，晕死～～待优化ing
        ListNode *cur = head, 
                 *newList = new ListNode(x),                //新链表头结点
                 *new_cur = newList;                        //新链表游标
        
        ListNode *pre = new ListNode(0), 
                 *head_node = new ListNode(0),              //原链表头结点
                 *tmp;
        pre->next = cur;
        head_node->next = head;
        //遍历，小于x的从原链表中删除，加入新链表
        while(cur != NULL){
            if(cur->val < x){
                tmp = cur;
                pre->next = cur->next;
                if(cur == head_node->next){                 //待删元素是第一个元素特别处理
                    head_node->next = cur->next;
                }
                cur = cur->next;
                
                tmp->next = NULL;
                new_cur->next = tmp;
                new_cur = new_cur->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        //连接两个链表
        new_cur->next = head_node->next;
        return newList->next;                   //注意返回第一个元素而非头结点
    }


//================================头插法实现============================//
    void partition(ListNode * &head, int x){    //头结点变化情况下，须声明为ListNode* &head或ListNode **head
        if(head == NULL){
            cout << "空链表" << endl;
            return;
        }
        if(head->next == NULL){
            cout << "单节点链表" << endl;
            return;
        }
        ListNode *cur = head,
                 *pre = new ListNode(0),
                 *head_node = new ListNode(0);
        pre->next = head;
        head_node->next = head;

        while(cur != NULL){
            if(cur->val < x && cur != head){
                pre->next = cur->next;
                cur->next = head_node->next;
                head_node->next = cur;
                cur = pre->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        head = head_node->next;
        
    } 
};

#endif
