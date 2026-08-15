class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* prev = NULL;
    TreeNode* mid = NULL;
    TreeNode* last = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && root->val < prev->val) {

            if (first == NULL) {
                first = prev;
                mid = root;
            }
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else
            swap(first->val, mid->val);
    }
};