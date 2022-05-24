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
    int val = 0;
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->right);
        val += root->val;
        root->val = val;
        inorder(root->left);
        return;
    }
};