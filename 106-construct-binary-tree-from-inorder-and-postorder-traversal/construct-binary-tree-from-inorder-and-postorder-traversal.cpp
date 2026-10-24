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

    int index;

    TreeNode* fun(vector<int>&postorder,int low,int high,unordered_map<int,int>&m){
        
         if(high < low) return NULL;

         TreeNode* node=new TreeNode(postorder[index]);
         index--;

         int id=m[node->val];
         
         node->right=fun(postorder,id+1,high,m);
         node->left=fun(postorder,low,id-1,m);

         return node;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;

        index=inorder.size()-1;
        return fun(postorder,0,m.size()-1,m);
    }
};