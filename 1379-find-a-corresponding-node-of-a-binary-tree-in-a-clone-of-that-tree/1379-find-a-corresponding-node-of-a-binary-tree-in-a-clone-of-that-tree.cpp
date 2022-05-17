/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<char> res;
        vector<char> dir;
        dfs(original , target , dir , res);
        for(auto& i : res){
            if( i == 'l') cloned = cloned->left;
            else cloned = cloned->right;
        }
        return cloned;
        
    }
    void dfs(TreeNode* o , TreeNode* t , vector<char>& d , vector<char>& res){
        if(!o) return;
        if( o == t ){
            res = d;
            return;
        }
        if(o->left){
            d.push_back('l');
            dfs(o->left , t , d , res);
            d.pop_back();
        }
        if(o->right){
            d.push_back('r');
            dfs(o->right , t , d , res);
            d.pop_back();
        }
        return;
    }
};