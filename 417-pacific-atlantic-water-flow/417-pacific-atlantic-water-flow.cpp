class Solution {
public:
    vector<vector<int>> visited , res;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()) return {};
        int n = heights.size() , m = heights[0].size();
        visited.resize( n , vector<int>(m , 0));
        for(int i = 0 ; i < n ; i++){
            dfs(heights , i , 0 , INT_MIN , 1);
            dfs(heights , i , m - 1 , INT_MIN , 2);
        }
        for(int i = 0 ; i < m ; i++){
            dfs(heights , 0 , i , INT_MIN , 1);
            dfs(heights , n - 1 , i , INT_MIN , 2);
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& heights , int x , int y , int pre , int visval){
        if( x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || heights[x][y] < pre || (visited[x][y] & visval) == visval )
            return;
        
        visited[x][y] |= visval;
        if( visited[x][y] == 3 ) res.push_back({x , y});
        dfs(heights , x - 1 , y , heights[x][y] , visited[x][y]);
        dfs(heights , x , y - 1 , heights[x][y] , visited[x][y]);
        dfs(heights , x + 1 , y , heights[x][y] , visited[x][y]);
        dfs(heights , x , y + 1 , heights[x][y] , visited[x][y]);
    }
};