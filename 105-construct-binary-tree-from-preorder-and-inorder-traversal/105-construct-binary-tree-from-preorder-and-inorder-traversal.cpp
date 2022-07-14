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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> pos;
        int n = preorder.size();
        for(int i = 0; i < n ; i++){
            pos[inorder[i]] = i;
        }
        return builder(preorder , inorder , 0 , 0 , n - 1 , pos);
    }
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder ,int preStart , int inStart , int inEnd , unordered_map<int , int>& pos ){
        if (preStart > preorder.size() - 1 || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = pos.find(root->val)->second;
        root->left = builder(preorder , inorder , preStart + 1 , inStart , inIndex - 1 , pos);
        root->right = builder(preorder , inorder , preStart + inIndex - inStart + 1 , inIndex + 1 , inEnd, pos);
        return root;
    }
};






















