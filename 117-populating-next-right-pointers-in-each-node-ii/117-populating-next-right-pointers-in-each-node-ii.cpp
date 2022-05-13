/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if( !root ) return root;
        int curr = 0;
        queue<pair< Node*, int>> q;
        if( root->left ) q.push({root->left , 1});
        if( root->right ) q.push({root->right , 1});
        Node* prev = root;
        while( !q.empty()){
            Node* temp = q.front().first;
            int level = q.front().second;
            q.pop();
            if( temp->left ) q.push({temp->left , level + 1});
            if( temp->right ) q.push({temp->right , level + 1});
            if( curr == level ){
                prev->next = temp;
            } else {
                prev->next = nullptr;
                curr = level;
            }
            prev = temp;
        }
        return root;
    }
};