#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA, lenB;

        lenA = getListLen(headA);
        lenB = getListLen(headB);

        ListNode *tmpA, *tmpB;

        tmpA = headA;
        tmpB = headB;

        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                tmpA = tmpA->next;
            }
        } else if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; i++) {
                tmpB = tmpB->next;
            }
        }

        while (tmpA != NULL) {
            if (tmpA == tmpB) {
                return tmpA;
            }

            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }

        return NULL;
    }


    int getListLen(ListNode *l) {
        int len;

        len = 0;

        while (l != NULL) {
            len += 1;
            l = l->next;
        }

        return len;
    }
};