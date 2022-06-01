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
    int rob(TreeNode* root) {
        dfs(root);
        return root->val;
    }
    
    void dfs( TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        root->val = max(root->val +  
                        (root->left != nullptr ? (gv(root->left->left) + gv(root->left->right)) : 0) + 
                        (root->right != nullptr ? (gv(root->right->left) + gv(root->right->right)) : 0)  
                        , gv(root->left) + gv(root->right));
    }
    
    int gv(TreeNode* root){
        if(!root) return 0;
        return root->val;
    }
};