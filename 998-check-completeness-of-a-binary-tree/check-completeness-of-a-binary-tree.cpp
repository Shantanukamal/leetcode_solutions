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
    bool isCompleteTree(TreeNode* root) {
        
        if(root==NULL) return 1;
        
        queue<TreeNode*>q;
        q.push(root);
        bool seen=0;
        
        while(!q.empty()){

            TreeNode* t=q.front();
            q.pop();

            if(t==NULL){
                seen=1;
                continue;
            }

            if(seen==1) return 0;

            q.push(t->left);
            q.push(t->right);
        }


        return 1;

    }
};