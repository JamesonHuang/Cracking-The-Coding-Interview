/*************************************************************************
	> File Name:        Solution.h
	> Description:     
                        （1）问题描述：
                            A.有两个链表，每个结点含一个数位
                            B.两个链表代表两个整数
                            C.求两个整数之和
                            D.链表形式返回结果
                            E.数位分反向存放与正向存放两种情况
	> Conclusion:          
                        （1）反向策略一：转为整型
                            A.声明两个加数变量
                            B.遍历两个链表
                            C.将结点的数位转到加数变量中
                            D.相加赋值到sum变量
                            E.链表形式逐位输出
                            F.关键公式：
                                a.v += p->data * pow(10,i)

                        （2）反向策略二：诸位添加
                            A.加入进位标志
                            B.将原有的两个链表对应结点值相加
                            C.所得之和插入新建链表中
                            D.进位标志为1时，注意所得之和需加1
                     
                        （3）策略二需注意一下问题
                            A.其中一个链表已空，而另一链表还有元素
                            B.当两个链表为空时，进位标志仍为1
                            C.代码优化与复用，防止重复代码
                        
                        （4）新建结点相关：
                            A.如果可以，不用临时结点
                            B.减少相关指针，防止指针太多，影响思路
                        
                        （5）代码路径与优化：
                            A.存在多条代码路径时，需注意优化
                            B.尽可能找出路径之间的重合与关联
                            C.缩减/优化代码

                        （6）正向存放待实现～～

    > Author:           rh_Jameson
	> Created Time:     2014年12月18日 星期四 11时48分40秒
 ************************************************************************/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
//=========================最终版：AC，省去多余指针=========================//
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res_head = new ListNode(0), *cur = res_head;
        int flag = 0, tmp_value = 0;
        while(l1 != NULL || l2 != NULL || flag){
            //计算和
            if(l1 != NULL){
                tmp_value += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                tmp_value += l2->val;
                l2 = l2->next;
            }
            tmp_value += flag;
            //判断是否有进位
            if(tmp_value >= 10){
                flag = 1;
                tmp_value %= 10;
            }
            else{
                flag = 0;
            }
            //加入新结点
            cur->next = new ListNode(tmp_value);
            cur = cur->next;
            tmp_value = 0;
        }
        return res_head->next;
    }

//=========================优化版2：AC，代码细节优化========================//
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //判两链表是否都为空
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        ListNode *res_head = new ListNode(0), *cur = res_head, *tmp;
        ListNode *cur_l1 = l1, *cur_l2 = l2;
        int flag = 0, tmp_value = 0;
        while(cur_l1 != NULL || cur_l2 != NULL || flag){
            //计算和
            if(cur_l1 != NULL){
                tmp_value += cur_l1->val;
                cur_l1 = cur_l1->next;
            }
            if(cur_l2 != NULL){
                tmp_value += cur_l2->val;
                cur_l2 = cur_l2->next;
            }
            tmp_value += flag;
            //判断是否有进位
            if(tmp_value >= 10){
                flag = 1;
                tmp_value %= 10;
            }
            else{
                flag = 0;
            }
            //加入新结点
            cur->next = new ListNode(tmp_value);
            cur = cur->next;
            tmp_value = 0;
        }
        return res_head->next;
    }


//====================优化版：AC，代码复用优化==============================//
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //判两链表是否都为空
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        
        ListNode *res_head = new ListNode(0), *cur = res_head, *tmp;
        ListNode *cur_l1 = l1, *cur_l2 = l2;
        int flag = 0;
        int tmp_value;
        
        while(cur_l1 != NULL || cur_l2 != NULL){
            //l1链表空，l2还有结点的情况
            if(cur_l1 == NULL){
                tmp_value = cur_l2->val + flag;
                cur_l2 = cur_l2->next;
            }
            //l2链表空，l1还有结点的情况
            else if(cur_l2 == NULL){
                tmp_value = cur_l1->val + flag;
                cur_l1 = cur_l1->next;
            }
            //l1,l2均有链表的情况
            else{
                tmp_value = cur_l1->val + cur_l2->val + flag;
                cur_l1 = cur_l1->next;
                cur_l2 = cur_l2->next;
            }
            //判断是否有进位
            if(tmp_value >= 10){
                flag = 1;
                tmp_value %= 10;
            }
            else{
                flag = 0;
            }
            //加入新结点
            tmp = new ListNode(tmp_value);
            tmp->next = NULL;
            cur->next = tmp;
            cur = cur->next;
        }
        if(flag == 1){
            tmp = new ListNode(1);
            tmp->next = NULL;
            cur->next = tmp;
            flag = 0;
        }
        return res_head->next;
    }

//====================原始版：AC，但代码冗长，重复太多======================//
    void addTwoNumbers(ListNode *l1, ListNode *l2) {
       ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        
        ListNode *res_head = new ListNode(0), *cur = res_head, *tmp, *new_node;
        ListNode *cur_l1 = l1, *cur_l2 = l2;
        int flag = 0;
        int tmp_value;
        while(cur_l1 != NULL || cur_l2 != NULL){
            //l1链表空，l2还有结点的情况
            if(cur_l1 == NULL){
                tmp = cur_l2;
                while(flag == 1){
                    cur_l2->val += flag;
                    if(cur_l2->val >= 10){
                        cur_l2->val %= 10;
                        if(cur_l2->next != NULL){
                            cur_l2 = cur_l2->next;
                        }
                        else{
                            new_node = new ListNode(1);
                            cur_l2->next = new_node;
                            flag = 0;
                        }
                        
                    }
                    else{
                        flag = 0;
                    }
                }
                cur->next = tmp;
                break;
            }
            //l2链表空，l1还有结点的情况
            if(cur_l2 == NULL){
                tmp = cur_l1;
                while(flag == 1){
                    cur_l1->val += flag;
                    if(cur_l1->val >= 10){
                        cur_l1->val %= 10;
                        if(cur_l1->next != NULL){
                            cur_l1 = cur_l1->next;
                        }
                        else{
                            new_node = new ListNode(1);
                            cur_l1->next = new_node;
                            flag = 0;
                        }
                    }
                    else{
                        flag = 0;
                    }
                }
                cur->next = tmp;
                break;
            }
            
            if(flag == false){
                tmp_value = cur_l1->val + cur_l2->val;
            }
            else{
                tmp_value = cur_l1->val + cur_l2->val + flag;
                flag = 0;
            }
            
            if(tmp_value >= 10){
                flag = 1;
                tmp_value %= 10;
            }
            tmp = new ListNode(tmp_value);
            tmp->next = NULL;
            cur->next = tmp;
            cur = cur->next;
            
            cur_l1 = cur_l1->next;
            cur_l2 = cur_l2->next;
        }
        if(flag == 1){
            new_node = new ListNode(1);
            new_node->next = NULL;
            cur->next = new_node;
            flag = 0;
          
        }
        return res_head->next;
    }
        
};

#endif
