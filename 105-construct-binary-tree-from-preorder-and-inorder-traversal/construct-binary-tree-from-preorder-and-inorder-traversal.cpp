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
    
    int index=0;

    TreeNode* fun(vector<int>&preorder,int low,int high,unordered_map<int,int>&m){
        
         if(high < low) return NULL;

         TreeNode* node=new TreeNode(preorder[index]);
         index++;

         int id=m[node->val];
         
         node->left=fun(preorder,low,id-1,m);
         node->right=fun(preorder,id+1,high,m);

         return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;

        return fun(preorder,0,m.size()-1,m);
    }
};