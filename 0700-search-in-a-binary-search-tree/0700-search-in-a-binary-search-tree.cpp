/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool search(TreeNode* root, int tar, TreeNode*& ans) {
        if (root == NULL) {
            return false;
        }
        if (root->val == tar) {
            ans = root;
            return true;
        }
        if (search(root->left, tar, ans))
            return true;
        if (search(root->right, tar, ans))
            return true;
        return false;
    }
    TreeNode* searchBST(TreeNode* root, int tar) {
        TreeNode* ans = NULL;
        search(root, tar, ans);
        return ans;
    }
};