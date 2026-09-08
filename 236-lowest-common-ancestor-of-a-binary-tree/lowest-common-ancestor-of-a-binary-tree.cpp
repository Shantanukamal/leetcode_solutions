/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int fun(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){

        if(root==NULL) return 0;

        int left=fun(root->left,p,q,ans);
        int right=fun(root->right,p,q,ans);
        int self=0;
         
        if(root==p || root==q) self=1;

        int total=left+right+self;

        if(total==2 && ans==NULL) ans=root;

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode*ans=NULL;
        fun(root,p,q,ans);

        return ans;
          
    }
};