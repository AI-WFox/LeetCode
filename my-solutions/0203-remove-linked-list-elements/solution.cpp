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
    ListNode* createNode (int val) {
        ListNode* node = new ListNode(val);
        return node;
    }

    void pushBack (ListNode* &head, int val) {
        if (head == nullptr) {
            head = createNode(val);
            return;
        }

        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = createNode(val);
    }

public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (cur->val != val) {
                pushBack(res, cur->val);
            }
            cur = cur->next;
        }

        return res;
    }
};
