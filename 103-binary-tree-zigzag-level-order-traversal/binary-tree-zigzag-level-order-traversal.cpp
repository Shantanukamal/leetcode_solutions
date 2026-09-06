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
    void fun(TreeNode* root,vector<vector<int>>&ans){

        queue<TreeNode*>q;
        q.push(root);
        bool zigzag=0;
        while(!q.empty()){

            int size=q.size();
            vector<int>temp(size);
            int front=0,last=size-1;
            while(size--){
                TreeNode* t=q.front();
                q.pop();

                if(zigzag==0){
                    temp[front]=t->val;
                    front++;
                }

                else{
                    temp[last]=t->val;
                    last--;
                }
                
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
               
            }
            
            if(zigzag==0) zigzag=1;
            else zigzag=0;
            ans.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        fun(root,ans);
        return ans;
    }
};