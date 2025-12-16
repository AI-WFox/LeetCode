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
class Solution {
private: 
    void removeNode (ListNode* head) {
        ListNode* cur = head;
        ListNode* preCur = head;
        while (cur != nullptr) {
            if (preCur->val != cur->val) {
                preCur->next = cur;
                preCur = preCur->next;
            }
            cur = cur->next;
        }
        if (preCur != nullptr) preCur->next = nullptr;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        removeNode(head);
        return head;
    }
};
