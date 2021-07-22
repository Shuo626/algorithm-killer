#include <bits/stdc++.h>


using namespace std;


class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node (int val): val(val), next(nullptr), random(nullptr) {}
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        map<Node*, Node*> oldToNew;

        Node *newHead, *last, *tmp, *oldTmp;

        newHead = deepCopy(head);
        oldToNew[head] = newHead;

        last = newHead;
        oldTmp = head->next;

        while (oldTmp != nullptr) {
            tmp = deepCopy(oldTmp);
            oldToNew[oldTmp] = tmp;

            last->next = tmp;
            last = tmp;

            oldTmp =oldTmp->next;
        }

        last->next = nullptr;
        
        oldTmp = head;
        tmp = newHead;

        while (oldTmp != nullptr) {
            if (oldTmp->random == nullptr) {
                tmp->random = nullptr;
            } else {
                tmp->random = oldToNew[oldTmp->random];
            }

            oldTmp = oldTmp->next;
            tmp = tmp->next;
        }

        return newHead;
    }


    Node* deepCopy(Node *n) {
        Node *rst = new Node(n->val);

        return rst;
    }
};