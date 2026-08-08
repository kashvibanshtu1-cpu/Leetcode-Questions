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
    bool valid(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;
        bool a = valid(root1->right, root2->left);
        bool b = valid(root1->left, root2->right);
        bool c = a && b;
        bool d = valid(root1->left, root2->left);
        bool e = valid(root1->right, root2->right);
        bool f = d && e;
        return c || f;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return valid(root1, root2);
    }
};