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
    ListNode* rev(ListNode* head){
        if(!head){
            return head;
        }
        ListNode* prev = head;
        ListNode* nxt = head->next;
        head->next = nullptr;
        while(nxt){
            ListNode* temp = nxt->next;
            nxt->next = prev;
            prev = nxt;
            nxt = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        // reverse the list starting from slow till the end;
        // set the previous to null
        prev->next = nullptr;
        ListNode* head2 = rev(slow);
        int turn  = 0;
        while(head && head2){
            ListNode* temp;
            if(turn%2 == 0){
                temp = head->next;
                head->next = head2;
                head = temp;
            }
            else{
                temp = head2->next;
                head2->next = head;
                head2 = temp;
            }
            turn++;
        }
    }
};
