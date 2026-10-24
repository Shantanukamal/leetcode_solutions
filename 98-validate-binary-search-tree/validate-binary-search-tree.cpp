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


    TreeNode* prev=NULL;
    bool ans=true;
    
    bool isValidBST(TreeNode* root) {
      
        if(root==NULL) return 0;

        isValidBST(root->left);

        if(prev==NULL) prev=root;
        else if(prev->val>=root->val) ans=0;
        else prev=root;
       
        isValidBST(root->right);

        return ans;
    }
};