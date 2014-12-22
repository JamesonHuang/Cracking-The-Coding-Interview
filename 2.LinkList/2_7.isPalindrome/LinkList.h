/*************************************************************************
	> File Name:        link_list_struct.h
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月16日 星期二 18时51分21秒
 ************************************************************************/

#ifndef _LINK_LIST_STRUCT_H
#define _LINK_LIST_STRUCT_H
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//链表结构
struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL){}
};

class Linklist{
public:
    //遍历输出链表元素
    void printLinkList(ListNode *head);
    //构建随机链表
    void constructLinkList(ListNode *head);
    //构建回文随即链表
    void constructPalidromeList(ListNode *head,int num); 
};


//构建回文随即链表
void Linklist::constructPalidromeList(ListNode *head,int num){
     srand( (int)time(NULL) );
    //尾插法
    ListNode *cur = head;
    const int tmp_mid = num / 2;
    int a[tmp_mid];
    for(int i = 0; i < tmp_mid; ++i){
        ListNode *tmp = new ListNode(0);
        tmp->val = rand() % 100;
        cur->next = tmp;
        cur = cur->next;

        a[i] = tmp->val;
    }
    for(int i = tmp_mid - 1; i >= 0; --i){
        ListNode *tmp = new ListNode(0);
        tmp->val = a[i];
        cur->next = tmp;
        cur = cur->next;
    }
}


void Linklist::printLinkList(ListNode *head){
    if(head == NULL){
        cout << "空链表" << endl;
    }
    ListNode *cur = head;
    while(cur != NULL){
        cout << cur->val << "\t";
        cur = cur->next;
    }
    cout << endl;
}

void Linklist::constructLinkList(ListNode *head){
    srand( (int)time(NULL) );
    int num = rand() % 20;
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
}

#endif
