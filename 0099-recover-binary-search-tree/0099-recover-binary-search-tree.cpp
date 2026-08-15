class Solution {
public:
    TreeNode* g_f = NULL;
    TreeNode* g_s = NULL;
    TreeNode* g2_f = NULL;
    TreeNode* g2_s = NULL;
    TreeNode* prev = NULL;

    void fun(TreeNode* root, int& count) {
        if (root == NULL)
            return;

        fun(root->left, count);

        if (prev != NULL && prev->val > root->val && count >= 1) {
            g2_f = prev;
            g2_s = root;
            count++;
        }

        if (prev != NULL && prev->val > root->val && count == 0) {
            g_f = prev;
            g_s = root;
            count++;
        }

        prev = root;

        fun(root->right, count);
    }

    void recoverTree(TreeNode* root) {
        int count = 0;

        fun(root, count);

        if (count == 1) {
            swap(g_f->val, g_s->val);
        }
        else {
            swap(g_f->val, g2_s->val);
        }
    }
};