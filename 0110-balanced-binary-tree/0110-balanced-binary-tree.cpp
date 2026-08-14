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
    bool ans = true;
    int valid(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = valid(root->left);
        int right = valid(root->right);
        int diff = abs(left - right);
        if (diff >= 2) {
            ans = false;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        valid(root);
        return ans;
    }
};