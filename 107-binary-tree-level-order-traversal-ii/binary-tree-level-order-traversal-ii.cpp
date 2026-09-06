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

        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){

            int size=q.size();
            vector<int>temp;
            while(size--){

                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
            }

            ans.push_back(temp);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        fun(root,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};