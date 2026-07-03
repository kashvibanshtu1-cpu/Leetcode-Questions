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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* joinend = head;
        int n = 1;
        while (joinend->next != NULL) {
            n++;
            joinend = joinend->next;
        }
        k = k % n;
        if (k == 0)
            return head;
        ListNode* end = head;
        for (int i = 0; i < n - k - 1; i++) {
            end = end->next;
        }
        ListNode* start = end->next;
        joinend->next = head;
        end->next = NULL;
        return start;
    }
};