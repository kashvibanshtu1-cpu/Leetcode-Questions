/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    int check(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return 0;
        }
        int left = check(root->left, p, q);
        int right = check(root->right, p, q);
        int self = 0;
        int sum;
        if (root->val == p->val || root->val == q->val) {
            self = 1;
        }
        sum = self + left + right;
        if (sum == 2 && ans == NULL) {
            ans = root;
        }
        return sum;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root, p, q);
        return ans;
    }
};