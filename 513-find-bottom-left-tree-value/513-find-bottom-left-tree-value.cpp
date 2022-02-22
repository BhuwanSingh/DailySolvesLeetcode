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
    int findBottomLeftValue(TreeNode* root) {
        int val = root->val;
        int depth  = 0;
        dfs(root , val , depth , 1);
        return val;
    }
    
    void dfs(TreeNode* root , int& val , int& depth , int curr){
        if(!root) return;
        if(curr > depth){
            val = root->val;
            depth = curr;
        }
        dfs(root->left , val , depth , curr + 1);
        dfs(root->right , val , depth , curr + 1);
        return;
    }
};