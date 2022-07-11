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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {} ;
        int level = 0;
        vector<int> res;
        res.push_back(root->val);
        dfs( root , res, 0 , level);
        return res;
    }
    
    void dfs( TreeNode* root , vector<int>& res , int cur , int& level){
        if(!root) return;
        
        if(cur > level){
            res.push_back(root->val);
            level = cur;
        }
        dfs( root->right , res, cur + 1 , level);
        dfs( root->left , res, cur + 1 , level);
        return;
    }
};