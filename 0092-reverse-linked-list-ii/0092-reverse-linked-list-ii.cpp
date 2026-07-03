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
        ListNode* curr = head;
        ListNode* prev = NULL;
        for (int i = 0; i < left - 1; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* before = prev;
        ListNode* end = curr;
        int times = right - left + 1;

        while (times--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        end->next = curr;
        if (before == NULL) {
            return prev;
        }
        before->next = prev;
        return head;
    }
};