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
    
    void fun(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*&ans){
        
        if(root==NULL) return;

        if(p->val<root->val && q->val<root->val) fun(root->left,p,q,ans);

        else if(p->val>root->val && q->val>root->val) fun(root->right,p,q,ans);

        else {
           ans=root;
           return;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode*ans=NULL;
        fun(root,p,q,ans);
        return ans;
    }
};