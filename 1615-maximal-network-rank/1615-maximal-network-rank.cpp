class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        for(auto i : roads){
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int temp = adj[i].size() + adj[j].size();
                if( adj[i].find(j) != adj[i].end() ){
                    temp--;
                }
                res = max(res , temp);
            }
        }
        return res;
    }
};