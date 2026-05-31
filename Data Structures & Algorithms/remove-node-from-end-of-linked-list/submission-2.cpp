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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        if(!head->next){
            return nullptr;
        }
        if(!head->next->next){
            if(n == 1){
                head->next = nullptr;
                return head;
            }
            else{
                head = head->next;
                return head;
            }
        }
        ListNode *f = head, *s = head;
        ListNode *prev = nullptr;
        int fc = 0, sc = 0;

        while(f && s){
            if(f->next){
                f = f->next;
                fc++;
                    // cout << f->val;
            }
            else{
                if(sc == fc - n + 1){
                    if(!prev){
                        return head->next;
                    }
                    ListNode* temp = s->next;
                    prev->next = s->next;
                    // delete temp;
                    break;
                }
                else{
                    prev = s;
                    s = s->next;
                    sc++;
                }
            }
        }
        return head;
    }
};
