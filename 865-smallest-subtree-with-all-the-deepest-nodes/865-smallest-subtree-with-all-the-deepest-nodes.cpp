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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
    
    pair<int , TreeNode* > dfs(TreeNode* root){
        if(!root) return { 0 , nullptr };
        pair<int , TreeNode*> left = dfs(root->left) , right = dfs(root->right);
        return { max(left.first , right.first) + 1 , left.first == right.first ? root : left.first > right.first ? left.second : right.second};
    }
};