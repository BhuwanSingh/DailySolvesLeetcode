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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue <pair< TreeNode* , int> > q;
        q.push({root , 0});
        int level = 0;
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int currlevel = q.front().second;
            q.pop();
            if( currlevel > level){
                res = 0;
                level = currlevel;
            }
            res += curr->val;
            if( curr->left ) q.push({curr->left , currlevel + 1});
            if( curr->right ) q.push({curr->right , currlevel + 1});
        }
        return res;
    }
};