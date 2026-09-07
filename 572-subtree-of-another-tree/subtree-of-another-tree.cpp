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
    
    bool isSame(TreeNode*p,TreeNode*q){
        
        if(p==NULL && q==NULL) return 1;
        if(p==NULL && q!=NULL || p!=NULL && q==NULL) return 0;
        if(p->val!=q->val) return 0;

        return (isSame(p->left,q->left) && isSame(p->right,q->right));

    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        
        if(root==NULL) return 0;
        
        if(isSame(root,subroot)) return 1;

        return(isSubtree(root->left,subroot)||isSubtree(root->right,subroot));
    }
};