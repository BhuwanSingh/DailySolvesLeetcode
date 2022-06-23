class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid , i , j);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& board , int x , int y){
        if( x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != '1') return;
        board[x][y] = '0';
        dfs(board , x , y - 1);
        dfs(board , x - 1, y );
        dfs(board , x , y + 1);
        dfs(board , x + 1, y );
    }
};