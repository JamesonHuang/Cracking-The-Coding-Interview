/*************************************************************************
	> File Name:        Solution.h
	> Description:     
                        (1)问题描述：
                            A.链表
                            B.判断是否是有环链表
                            C.返回环路开头结点
	
    > Conclusion:          
                        (1)策略 & 思路：快慢指针
                            A.设定一快一慢指针,p_fast & p_slow
                            B.p_slow走一步，p_fast走两步
                            
                            C.设p_slow走k步进入环，到达环的入口接点
                                a.此时，p_slow = k, p_fast = 2k
                                b.快慢相距 （p_fast - p_slow）k 步
                            
                            D. 设环总长度为L，则快慢反向相距L - k步
                            
                            E.快慢指针每移动一位，反向相距长度就减一
                                a.移动L - k次后，快慢相遇
                                b.此时慢指针在环内走了L - k步
                            
                            F.即慢指针距离入口结点：
                                    L - （L - k） = k
                            G.快慢相遇后，慢指针指回头结点
                            H.快慢继续向前推进
                            I.当快慢指针的指向值相等时，即是环路开头结点
                        
                        (2)链表相关注意：
                            A.做链表题目时，一定要理清思路后再实现
                            B.注意边界用例特殊情况
                            C.最好能画图在纸上确保木有问题了再转成代码
                        
                        (1)问题描述：
                            A.
                            B.
                            C.
                            D. 
    > Author:           rh_Jameson
	> Created Time:     2014年12月19日 星期五 17时41分07秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
//===================快慢指针返回环入口结点：自增头结点版本====================//
    ListNode *detectCycle(ListNode *head) {
        //定义头结点，快慢指针
        ListNode *head_node = new ListNode(0);       //p_slow = NULL OK?
        head_node->next = head;
        ListNode *p_slow = head_node, *p_fast = head_node;
        
        while(p_slow != p_fast || p_slow == head_node){
            //如p_fast已指向链表尾部，返回NULL
            if(p_fast->next == NULL || p_fast->next->next == NULL){
                return NULL;
            }
            //快慢向前推进
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;
        }
        //慢指针重置
        p_slow = head_node;
        //快慢指针重新向前推进，直至相遇
        while(p_slow != p_fast){
            p_slow = p_slow->next;
            p_fast = p_fast->next;
        }
        return p_slow;
    }
//============快慢指针返回环入口结点：无头结点优化版本（非本人代码）=============//
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *detect = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == detect) return detect;
            if(slow == fast) detect = detect->next;
        }
        return NULL;
    }



//========================判断链表是否是有环链表========================//
    bool hasCycle(ListNode *head) {
        ListNode *head_node = new ListNode(0);       //p_slow = NULL OK?
        head_node->next = head;
        ListNode *p_slow = head_node, *p_fast = head_node;
        
        while(p_slow != p_fast || p_slow == head_node){
            if(!p_fast->next || !p_fast->next->next){
                return false;
            }
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;
        }
        return true;
    }

};

#endif
