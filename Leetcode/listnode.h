#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 调试用，打印整个链表
void print_list(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
class List
{
  public:
    ListNode *head, *tail;
    int pos;
    List()
    {
        head = nullptr;
        tail = nullptr;
    };
    // 用vector进行初始化
    List(const std::vector<int> &in)
    {
        head = nullptr;
        tail = nullptr;
        for (auto it : in)
            this->insert(it);
    };
    ~List(){};
    // 插入节点
    void insert(int x)
    {
        if (head == nullptr)
        {
            head = tail = new ListNode(x);
            head->next = nullptr;
            tail->next = nullptr;
        }
        else
        {
            ListNode *p = new ListNode(x);
            tail->next = p;
            tail = p;
            tail->next = nullptr;
        }
    };
    void print()
    {
        print_list(head);
    }
};
