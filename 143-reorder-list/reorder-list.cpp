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
    ListNode* rev(ListNode* h){
        ListNode* c = h, *p = NULL, *t;
        while(c) t = c->next, c->next = p, p = c, c = t;
        return p;
    }
    
    void reorderList(ListNode* head) {
        ListNode* s = head, *f = head, *h2 = NULL, *t1 = NULL, *t2 = NULL, *n1 = NULL, *n2 = NULL;
        while(f && f->next) s = s->next, f = f->next->next; // Find middle
        h2 = rev(s); // Reverse second half
        t1 = head, t2 = h2;
        while(t1 && t2){
            n1 = t1->next, n2 = t2->next;
            if(t1 != t2) t1->next = t2;
            if(t2 != n1) t2->next = n1;
            t1 = n1, t2 = n2;
        }
    }
};