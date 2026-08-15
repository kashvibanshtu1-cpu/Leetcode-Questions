/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp ;
    TreeNode* fun( vector<int>& postorder,int & indx,int low,int high){
        if(low>high){
            return NULL ;
        }
        TreeNode* root = new TreeNode(postorder[indx]);
        int pos = mp[postorder[indx]];
        indx-- ;
        root->right = fun(postorder,indx,pos+1,high);
        root->left = fun(postorder ,indx,low,pos-1);
        return root ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int indx = n-1 ;
        return fun(postorder,indx,0,n-1);
    }
};