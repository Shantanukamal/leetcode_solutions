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
   
    void fun(TreeNode* root, int target,int sum,vector<int>temp,vector<vector<int>>&ans){

          if(root==NULL) return;
          
          sum+=root->val;
          temp.push_back(root->val);

          if(root->left==NULL && root->right==NULL) {

               if(sum==target){
                   ans.push_back(temp);
                   return;
               }
          }

          fun(root->left,target,sum,temp,ans);
          fun(root->right,target,sum,temp,ans);

          return;
          
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        vector<int>temp;

        fun(root,targetSum,0,temp,ans);

        return ans;
    }
};