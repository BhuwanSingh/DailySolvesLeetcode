class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if( grid[i][j] == 1 ){
                    res = max(res , dfs(grid , i , j));
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid , int x , int y){
        if( x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1 )
            return 0;
        
        grid[x][y] = -1;
        return 1
            + dfs(grid , x - 1 , y)
            + dfs(grid , x , y - 1)
            + dfs(grid , x + 1 , y)
            + dfs(grid , x , y + 1);
    }
};