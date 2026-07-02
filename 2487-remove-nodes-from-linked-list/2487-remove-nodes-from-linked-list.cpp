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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr != NULL) {
            st.push(curr);
            curr = curr->next;
        }
        curr = st.top();
        st.pop();
        int maxnode = curr->val;
        ListNode* resulthead = new ListNode(curr->val);
        while (!st.empty()) {
            curr = st.top();
            st.pop();
            if (curr->val < maxnode) {
                continue;
            } else {
                ListNode* ans = new ListNode(curr->val);
                ans->next = resulthead;
                resulthead = ans;
                maxnode = curr->val;
            }
        }
        return resulthead;
    }
};