/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(vector<Node*>& vis, Node* node , Node* copy){
        vis[copy->val] = copy;
        
        for(auto curr : node->neighbors){
            if(vis[curr->val] == NULL){
                Node* newNode = new Node(curr->val);
                (copy->neighbors).push_back(newNode);
                dfs(vis, curr , newNode);
            } else {
                copy->neighbors.push_back(vis[curr->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        vector <Node*> vis(200, NULL);
        
        Node* copy = new Node(node->val);
        vis[node->val] = copy;
        
        for(auto curr : node->neighbors){
            if(vis[curr->val] == NULL){
                Node* newNode = new Node(curr->val);
                (copy->neighbors).push_back(newNode);
                dfs(vis, curr , newNode);
            } else {
                copy->neighbors.push_back(vis[curr->val]);
            }
        }
        return copy;
    }
};