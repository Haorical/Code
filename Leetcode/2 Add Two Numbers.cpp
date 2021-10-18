/*
2. 两数相加
https://leetcode-cn.com/problems/add-two-numbers/
递归
难度：中等 没做出来，还不能调试，服了
*/
#include<listnode.h>
#include<bits/stdc++.h>
using namespace std;
/*
错误版本
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* s = new ListNode();
        int x1=getNum(l1);
        int x2=getNum(l2);
        int sum=x1+x2;
        while(sum){
            int t = sum%10;
            sum/=10;
            s->val=t;
            s->next = new ListNode();
            s=s->next;
        }
        return s;
    }
    int getNum(ListNode* x){
        list<int> l;
        int num=0;
        while(x->next!=nullptr){
            l.push_front(x->val);
        }
        for(auto i:l){
            num=num*10+i;
        }
        return num;
    }
};
*/
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
// 正确的
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        ListNode* current = root; //相当于是个指针，每次进位都会移动到进位的节点
        int carry = 0;
        while(l1 || l2 || carry){
            int l1val = l1!=nullptr? l1->val:0;
            int l2val = l2!=nullptr? l2->val:0;
            int sumval = l1val+l2val+carry;
            carry = sumval/10;
            ListNode* sumNode = new ListNode(sumval%10);
            current->next = sumNode;
            current = sumNode;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return root->next;
    }
};
int main(){
    
    
}