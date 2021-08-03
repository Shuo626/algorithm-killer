#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, vector<ListNode*>> numToListNode;

        for (int i = 0; i < lists.size(); i++) {
            ListNode *tmp;

            tmp = lists[i];

            while (tmp != nullptr) {
                numToListNode[tmp->val].push_back(tmp);
                tmp = tmp->next;
            }
        }

        ListNode *prev, *ans;

        ans = new ListNode();
        prev = ans;

        for (auto &pair: numToListNode) {
            auto &nodes = pair.second;

            for (ListNode*& node: nodes) {
                prev->next = node;
                prev = node;
            }
        }

        return ans->next;
    }
};