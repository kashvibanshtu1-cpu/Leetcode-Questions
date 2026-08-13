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
    void valid(TreeNode* root, int tar, vector<int>& temp, int sum,
               vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == tar) {
                ans.push_back(temp);
            }
            temp.pop_back();
            return ;
        }
        valid(root->left, tar, temp, sum, ans);
        valid(root->right, tar, temp, sum, ans);
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        valid(root, tar, temp, sum, ans);
        return ans;
    }
};