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
        if(!head || !head->next){
            return head;
        }
        ListNode *nxt = head->next;
        ListNode *prev = head;
        head->next = nullptr;
        while(nxt){
            ListNode* temp = nxt->next;
            nxt->next = prev;
            prev = nxt;
            nxt = temp;
        }
        return prev;
    }
};
