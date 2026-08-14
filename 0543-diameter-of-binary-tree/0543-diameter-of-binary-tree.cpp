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
    int fun(TreeNode* root, int& ans) {
        if (root == NULL) {
            return -1;
        }
        int left = fun(root->left, ans);
        int right = fun(root->right, ans);
        int sum = left + right + 2;
        ans = max(ans, sum);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        fun(root, ans);
        return ans;
    }
};