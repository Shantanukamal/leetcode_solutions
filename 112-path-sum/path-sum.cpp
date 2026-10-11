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

    void fun(TreeNode* root, int target, bool &res,int sum){

        if(root==NULL) return ;
        
        sum+=root->val;
        //if leaf node
        if(root->left==NULL && root->right==NULL){
            
            if(sum==target) res=true;
            return;
        }

        fun(root->left,target,res,sum);
        fun(root->right,target,res,sum);

        return;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool res=false;
        fun(root,targetSum,res,0);

        return res;
       
    }
};