/*************************************************************************
	> File Name:        Solution.h
	> Description:      
                        （1）问题描述
                            A.未排序链表
                            B.移除重复节点
	> Conclusion:          
                        （1）策略一：
                            A.对链表排序
                            B.通过快慢指针消除重复元素
                        
                        （2）策略二：
                            A.哈希表储存元素
                            B.遍历链表
                            C.遇到重复元素，从链表中删去.
                        
                        （3）注意指针的命名方式
                        （4）
    > Author:           rh_Jameson
	> Created Time:     2014年12月16日 星期二 11时36分52秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<ctime>

using namespace std;


class Solution {
    
private:
    //链表结构
    struct ListNode{
        int val;
        ListNode* next;
        
        ListNode(int x) : val(x), next(NULL) {}
    }; 

public:
    void printLinkList(ListNode *head){
        if(head == NULL){
            cout << "空链表" << endl;
        }
        ListNode *cur = head;
        while(cur != NULL){
            cout << cur->val << "\t";
            cur = cur->next;
        }
    }
    //构建随机链表
    void constructLinkList(){
        
        srand( (int)time(NULL) );
        int num = rand() % 20;
        ListNode *head = new ListNode(0);        
        //头插法插入随机数据
        /*for(int i = 0; i < num; ++i){
            ListNode *tmp = new ListNode(0);
            tmp->val = rand() % 100;
            tmp->next = head->next;
            head->next = tmp;
            cout << tmp->val << "\t";
        }*/
        //尾插法
        ListNode *cur = head;
        for(int i = 0; i < num; ++i){
            ListNode *tmp = new ListNode(0);
            tmp->val = rand() % 100;
            cur->next = tmp;
            cur = cur->next;            
        }
        cout << endl;
        printLinkList(head);
        removeDuplicatesFromLinklist(head);
        cout << endl << endl;
        printLinkList(head);
    }
//=================哈希实现：空间O（M）,时间O（N）====================//
    void removeDuplicatesFromLinklist(ListNode *head){
        if(head == NULL){
            cout << "空链表" << endl;
        }
        map<int, int> unique_map;
        ListNode *p = head, *tmp = new ListNode(0);
        ListNode *q = head->next;
        unique_map[p->val] = p->val;
        
        for(q = head->next; q != NULL; q = q->next){
            if(unique_map.count(q->val)){
                p->next = q->next;
                tmp = q;
                q = p;
                delete tmp;
            }
            else{
                unique_map[q->val] = q->val;
                p = p->next;
            }
        }
    }

};

#endif
