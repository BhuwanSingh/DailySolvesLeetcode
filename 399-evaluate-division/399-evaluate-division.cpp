class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        
        unordered_map<string , unordered_map<string , double>> um;
        
        for(int i = 0; i < n ; i++){
            double val = values[i];
            string num = equations[i][0] , den = equations[i][1];
            um[num][num] = 1;
            um[den][den] = 1;
            um[num][den] = val;
            um[den][num] = 1 / val;
        }
        
        vector<double> res;
        unordered_set<string> visited;
        
        for(auto& query : queries){
            auto num = query[0] , den = query[1];
            visited = {num};
            res.push_back(dfs(num , den , um , visited));
        }
        return res;
    }
    
    double dfs(string num , string den , unordered_map<string , unordered_map<string , double>>& um , unordered_set<string> visited){
        if(um.find(num) == um.end())
            return -1;
        if(um[num].find(den) != um[num].end())
            return um[num][den];
        
        for(auto i : um[num]){
            if( visited.find(i.first) != visited.end())
                continue;
            visited.insert(i.first);
            double res;
            if((res = dfs(i.first , den , um , visited)) != -1)
                return um[num][den] = um[num][i.first] * res;
        }
        return -1;
    }
};