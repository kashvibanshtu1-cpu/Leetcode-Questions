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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> asc;
        int count = 0;
        TreeNode* t = root;
        while (t) {
            asc.push(t);
            t = t->left;
        }
        int ans;
        bool ones = false;
        while (!asc.empty() || count != k) {
            TreeNode* small = asc.top();
            asc.pop();
            count++;
            if (count == k && ones == false) {
                ans = small->val;
                ones = true;
                break;
            }
            TreeNode* rightchild = small->right;
            while (rightchild) {
                asc.push(rightchild);
                rightchild = rightchild->left;
            }
        }
        return ans;
    }
};