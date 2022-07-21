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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }

        int idx = 1;
        ListNode *before, *after, *last, *left_node, *right_node, *current_node;
        before = after = nullptr;
        current_node = head;

        while (true)
        {
            if (idx < left - 1)
            {
                current_node = current_node->next;
            }
            else if (idx == left - 1)
            {
                before = current_node;
                current_node = current_node->next;
            }
            else if (idx == left)
            {
                left_node = current_node;
                last = current_node;
                current_node = current_node->next;
            }
            else if (idx > left && idx <= right)
            {
                if (idx == right)
                {
                    right_node = current_node;
                }
                ListNode *tmp = current_node->next;
                current_node->next = last;
                last = current_node;
                current_node = tmp;
            }
            else if (idx == right + 1)
            {
                after = current_node;
                break;
            }

            idx += 1;
        }

        ListNode *rst;

        left_node->next = after;

        if (before == nullptr)
        {
            rst = right_node;
        }
        else
        {
            before->next = right_node;
            rst = head;
        }

        return rst;
    }
};
