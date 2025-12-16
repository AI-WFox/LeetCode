/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        ListNode* res = new ListNode;
        while (curA != nullptr) {
            curA->val = curA->val*-1;
            curA = curA->next;
        }

        while (curB != nullptr) {
            if (curB->val < 0) {
                res->val = curB->val*-1;
                break;
            }
            curB = curB->next;
        }

        curA = headA;
        while (curA != nullptr) {
            curA->val = curA->val*-1;
            curA = curA->next;
        }

        if (curB == nullptr) {
            return nullptr;
        }

        return res;
    }
};
