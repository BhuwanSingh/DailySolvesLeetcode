class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(vis[curr]) 
                continue;
            vis[curr] = true;
            if( curr == destination ) 
                return true;
            for(int i : adj[curr])
                q.push(i);
        }
        return false;
    }
};