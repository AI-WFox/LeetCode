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
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode* precur = nullptr;

        ListNode* cur = head;

        ListNode* nextcur = head->next;
        while (nextcur != nullptr) {
           cur->next = precur;
           precur = cur;
           cur = nextcur;
           nextcur = nextcur->next;
        }
        cur->next = precur;

        return cur;
    }
};
