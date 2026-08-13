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
    void valid(TreeNode* root, int &ans, int &num) {
        if (root == NULL)
            return;
        int digit = root->val;
        num = (num * 10) + digit;
        if (root->left == NULL && root->right == NULL) {
            ans += num;
            num = (num - digit) / 10;
            return;
        }
        valid(root->left, ans, num);
        valid(root->right, ans, num);
        num = (num - digit) / 10;
        return;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int num =0;
        valid(root, ans, num);
        return ans;
    }
};