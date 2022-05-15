class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n + 1);
        for(auto i : times){
            adj[i[0]].push_back({ i[1] , i[2] });
            // adj[i[1]].push_back({ i[0] , i[2] });
        }
        
        vector<int> dist(n + 1 , INT_MAX);
        dist[k] = 0;
        vector<bool> processed(n + 1 , false);
        
        for(int i = 0; i < n ; i++){
            int u = minDist(dist , processed);
            
            processed[u] = true;
            for(auto k : adj[u]){
                if(dist[k.first] > dist[u] + k.second){
                    dist[k.first] = dist[u] + k.second;
                }
            }
        }
        
        int maxval = 0;
        for(int i = 1 ; i <= n ; i++){
            maxval = max(dist[i] , maxval);
        }
        return maxval < INT_MAX ? maxval : -1;
        
    }
    
    int minDist(vector<int>& dist , vector<bool>& processed ){
        
        int u = 0;
        int minval = INT_MAX;
        for(int i = 1 ; i < dist.size() ; i++ ){
            if(dist[i] < minval && processed[i] == 0){
                minval = dist[i];
                u = i;
            }
        }
        return u;
    }
};