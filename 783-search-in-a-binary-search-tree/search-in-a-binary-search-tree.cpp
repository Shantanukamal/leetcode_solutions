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
    
    void fun(TreeNode* root, int value,TreeNode*&ans){

        if(root==NULL) return;
        
        if(root->val==value) ans=root;

        else if(root->val>value) fun(root->left,value,ans);
        
        else fun(root->right,value,ans);

    }

    TreeNode* searchBST(TreeNode* root, int value) {
        
        TreeNode* ans=NULL;
        fun(root,value,ans);
        return ans;      
    }
};