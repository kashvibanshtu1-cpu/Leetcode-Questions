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
    void reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        while (times--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return;
    }
    ListNode* swapPairs(ListNode* head) {
        int k = 2;
        ListNode* left = head;
        ListNode* nextleft;
        ListNode* right;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;
        while (true) {
            right = left;
            for (int i = 0; i < k - 1; i++) {
                if (right == NULL)
                    break;
                right = right->next;
            }
            if (right) {
                nextleft = right->next;
                reverse(left, k);
                if (prevleft) {
                    prevleft->next = right;
                }
                prevleft = left;
                if (res == NULL) {
                    res = right;
                }
                left = nextleft;
            } else {
                if (prevleft) {
                    prevleft->next = left;
                }
                if (res == NULL) {
                    return left;
                }
                break;
            }
        }
        return res;
    }
};