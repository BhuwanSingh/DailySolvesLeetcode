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
    vector<int > nodes;
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(nodes.begin() , nodes.end() , [&](int& a , int& b){
            return a < b;
        });
        int i = 0;
        ino(root , i);
        // return root;
    }
    
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }
    
    void ino(TreeNode* root ,int& i){
        if(!root) return;
        ino(root->left , i);
        root->val = nodes[i];
        i++;
        ino(root->right , i);
    }
};