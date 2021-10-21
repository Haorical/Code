/*
21. 合并两个有序链表
https://leetcode-cn.com/problems/merge-two-sorted-lists/
递归
难度：简单 感觉代码没问题但一直时间超限
*/
#include<bits/stdc++.h>
#include<listnode.h>
using namespace std;
/*
我的代码
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* root=new ListNode(0);
        ListNode* current=root;
        while(p1!=nullptr&&p2!=nullptr){
            int tmp = 0;
            if(p1->val>p2->val){
                tmp=p2->val;
                p2=p2->next;
                ListNode* t=new ListNode(tmp);
                current->next = t;
                current = t;
            }else{
                tmp=p1->val;
                p1=p1->next;
                ListNode* t=new ListNode(tmp);
                current->next = t;
                current = t;                                
            }
        }
        //下面while用错了，应该用if，果然改了之后a完了
        if(p1!=nullptr){
            current->next=p1;
        }
        ifp2!=nullptr){
            current->next=p2;
        }
        return root->next;
    }
};
*/

//递归的方法 挺好理解的
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2; //只剩l2
        else if(l2==nullptr) return l1;//只剩l1
        else if(l1->val<l2->val){//l1值更小，l1 next指针指向剩下的merge之后的
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoLists(l2->next,l1);
            return l2;
        }
    }
};

//迭代，与我写的类似

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(-1);

        ListNode* current = root;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        current->next = (l1 == nullptr) ? l2 : l1;

        return root->next;
    }
};
