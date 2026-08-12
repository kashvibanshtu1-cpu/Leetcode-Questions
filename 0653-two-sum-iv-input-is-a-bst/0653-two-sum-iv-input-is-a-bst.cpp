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
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) {
            return false;
        }
        stack<TreeNode*> asc;
        stack<TreeNode*> dsc;
        TreeNode* t = root;
        // for ascending
        while (t) {
            asc.push(t);
            t = t->left;
        }
        // for descending
        t = root;
        while (t) {
            dsc.push(t);
            t = t->right;
        }
        while (!asc.empty() && !dsc.empty()) {
            TreeNode* small = asc.top();
            TreeNode* big = dsc.top();
            if (small == big) {
                return false;
            }
            int sum = small->val + big->val;
            if (sum == k) {
                return true;
            }

            if (sum < k) {
                asc.pop();
                TreeNode* rightchild = small->right;
                while (rightchild) {
                    asc.push(rightchild);
                    rightchild = rightchild->left;
                }
            } else {
                dsc.pop();
                TreeNode* leftchild = big->left;
                while (leftchild) {
                    dsc.push(leftchild);
                    leftchild = leftchild->right;
                }
            }
        }
        return false;
    }
};