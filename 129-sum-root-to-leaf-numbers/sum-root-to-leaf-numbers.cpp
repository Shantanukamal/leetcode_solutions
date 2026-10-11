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

    void fun(TreeNode* root,string num,int &ans){

        if(root==NULL) return ;
        
        num+=to_string(root->val);

        //leaf Node
        if(root->left==NULL && root->right==NULL){ 
          
            ans+=stoi(num);
            return;
        }
        
        fun(root->left,num,ans);
        fun(root->right,num,ans);

    }
    int sumNumbers(TreeNode* root) {
        
        int ans=0;
        string num="";
        fun(root,num,ans);

        return ans;
    }
};