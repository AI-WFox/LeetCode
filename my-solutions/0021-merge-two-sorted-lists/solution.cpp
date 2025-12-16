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

    void traverse (ListNode* & head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
        }
    }

    void pushBack (int val, ListNode* & head) {
        if (head == nullptr) {
            head = createNode (val);
            return;
        }

        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = createNode (val);
    }

    ListNode* mergeList (ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                pushBack(list1->val, head);
                list1 = list1->next;
            } else {
                pushBack(list2->val, head);
                list2 = list2->next;
            }
        }

        while (list1 != nullptr) {
            pushBack(list1->val, head);
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            pushBack(list2->val, head);
            list2 = list2->next;
        }

        return head;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return mergeList(list1, list2);
    }
};
