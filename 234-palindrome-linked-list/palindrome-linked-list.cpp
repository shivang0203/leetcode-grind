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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=NULL;
        ListNode* sCopy = slow;
        while(sCopy){
            ListNode*temp= sCopy->next;
            sCopy->next=curr;
            curr=sCopy;
            sCopy=temp;
        }
        while(curr){
            if(head->val !=curr->val)return false;
            head=head->next;
            curr=curr->next;
        }
        return true;
    }
};