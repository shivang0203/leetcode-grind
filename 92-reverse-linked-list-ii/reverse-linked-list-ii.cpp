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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* reverseTail = curr;

        for (int i = 0; i < right - left + 1; ++i) {
            next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }

        reverseTail->next = curr;

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
