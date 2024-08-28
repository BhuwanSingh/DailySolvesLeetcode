class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int n = grid1.length, m = grid1[0].length;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if( grid1[i][j] == 0 )
                    dfs(i , j , grid2);
            }
        }

        int count = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if( grid2[i][j] == 1){
                    dfs(i , j , grid2);
                    count++;
                }
            }
        }
        return count;
    }

    public void dfs(int r , int c , int[][] grid){
        if( r < 0 || c < 0 || r == grid.length || c == grid[0].length || grid[r][c] == 0)
            return;

        grid[r][c] = 0;
        dfs(r + 1, c , grid);
        dfs(r - 1, c , grid);
        dfs(r , c + 1, grid);
        dfs(r , c - 1, grid);
    }
}