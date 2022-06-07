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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums , int l = 0  , int r = -9) {
        if( r == -9) r = nums.size() - 1;
        int maxval = l;
        if( r < l ) return nullptr;
        for(int i = l; i <= r ; i++){
            if( nums[i] > nums[maxval]){
                maxval = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxval]);
        root->left = constructMaximumBinaryTree(nums , l , maxval - 1);
        root->right = constructMaximumBinaryTree(nums , maxval + 1 , r);
        return root;
    }
};