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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }

        int leftToRight = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelsize = q.size();
            int first = 0;
            int last = levelsize - 1;
            vector<int> temp(levelsize);
            while (levelsize--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
                if (leftToRight == 1) {
                    temp[first] = t->val;
                    first++;
                } else {
                    temp[last] = t->val;
                    last--;
                }
            }
            res.push_back(temp);
            leftToRight = 1 - leftToRight;
        }
        return res;
    }
};