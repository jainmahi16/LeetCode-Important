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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1list = new ListNode(0, nullptr);
        ListNode* l2list = new ListNode(0, nullptr);
        ListNode* small = l1list;
        ListNode* big = l2list;

        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }

        small->next = l2list->next;
        big->next = nullptr;

        ListNode* result = l1list->next;
        delete l1list;
        delete l2list;
        return result;        
    }
};