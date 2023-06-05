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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > res;
        ino(res , root);
        return res;
    }
    
    void ino( vector< int >& res , TreeNode* root ){
        if(!root) return;
        ino(res , root->left);
        res.push_back(root->val);
        ino(res , root->right);
        
    }
};