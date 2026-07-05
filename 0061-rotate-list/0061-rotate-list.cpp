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
        if(head==NULL){
            return NULL;
        }
        int n = 1;
        ListNode* last = head;
        while (last !=NULL &&last->next != NULL) {
            n++;
            last = last->next;
        }
        k = k%n;
        if(k==0){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        for (int i = 0; i < n - k; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        last->next = head;
        return curr;
    }
};