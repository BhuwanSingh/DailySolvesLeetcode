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
class BSTIterator {
    void in_o(TreeNode* root){
        if(!root) return ;
        in_o(root->left);
        res.push_back(root->val);
        in_o(root->right);
    }
public:
    vector<int> res;
    int i = 0;
    BSTIterator(TreeNode* root) {
        in_o(root);
    }
    
    int next() {
        return res[i++];
    }
    
    bool hasNext() {
        if(i >= res.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */