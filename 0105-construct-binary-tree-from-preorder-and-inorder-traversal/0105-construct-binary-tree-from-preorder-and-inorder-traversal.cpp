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
    unordered_map<int, int> mp;
    TreeNode* fun(vector<int>& preorder, int &indx, int low, int high) {
        if (low > high) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[indx]);
        int pos = mp[preorder[indx]];
        indx++;
        root->left = fun(preorder, indx, low, pos - 1);
        root->right = fun(preorder, indx, pos + 1, high);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] =i;
        }
        int indx = 0;
        return fun(preorder, indx, 0, n - 1);
    }
};