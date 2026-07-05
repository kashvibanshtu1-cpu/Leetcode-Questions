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
        if (head == NULL) {
            return NULL;
        }
        ListNode* before;
        ListNode* t = head;
        for (int i = 0; i < left - 1; i++) {
            before = t;
            t = t->next;
        }
        ListNode* prevleft = t;
        ListNode* curr = t;
        ListNode* prev = NULL;
        ListNode* next;
        int times = right - left + 1;
        while (times--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prevleft->next = curr;
        if (before == NULL) {
            return prev;
        }
        before->next = prev;
        return head;
    }
};