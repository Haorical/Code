/*
203. 移除链表元素
https://leetcode-cn.com/problems/remove-linked-list-elements/
递归
难度：入门
*/
#include<bits/stdc++.h>
#include "listnode.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//迭代版本
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* front=new ListNode(-1);
        front->next=head;
        ListNode* current=front;
        while(current->next!=nullptr){
            if(current->next->val==val){
                current->next=current->next->next;
            }else{

                current=current->next; //bug位置，这句话老忘写

            }
        }
        return front->next;
    }
};

//递归版本 很简单就几行
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        head->next=removeElements(head->next,val);
        return head->val==val?head->next:head; //判断返回头节点还是下一个
    }
};



int main(){

}