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
    bool valid = false ;
    int lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == NULL) {
            return 0;
        }
        int left = lca(root->left, p, q, ans);
        int right = lca(root->right, p, q, ans);
        int self = left + right;
        if (root->val == p->val || root->val == q->val) {
            self = 1 + self;
        }
        if (self == 2 && valid == false ) {
            ans = root;
            valid = true ;
        }
        return self;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        lca(root, p, q, ans);
        return ans;
    }
};