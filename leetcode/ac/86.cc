#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small, *small_head, *big, *big_head;
        small_head = new ListNode(0, nullptr);
        big_head = new ListNode(0, nullptr);
        small = small_head;
        big = big_head;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                small->next = head;
                small = head;
            }
            else
            {
                big->next = head;
                big = head;
            }
            head = head->next;
        }

        big - next = nullptr;
        small->next = big_head->next;
        ListNode *rst = small_head->next;

        return rst;
    }
};
