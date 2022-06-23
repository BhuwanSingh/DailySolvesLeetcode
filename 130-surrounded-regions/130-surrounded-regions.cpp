class Solution {
public:
    void solve(vector<vector<char>>& board) {
        edges(board);
        for(int i = 0 ; i < board.size() ; i++ ){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == 'a'){
                    board[i][j] = 'O';
                } else board[i][j] = 'X';
            }
        }
    }
    
    void edges(vector<vector<char>>& board){
        int n = board.size() , m = board[0].size();
        for(int i = 0; i < n ; i++){
            dfs(board , i , 0);
            dfs(board , i , m - 1);
        }
        for(int i = 0; i < m ; i++){
            dfs(board , 0 , i);
            dfs(board , n - 1 , i);
        }
    }
    
    void dfs(vector<vector<char>>& board , int x , int y){
        if( x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') return;
        board[x][y] = 'a';
        dfs(board , x , y - 1);
        dfs(board , x - 1, y );
        dfs(board , x , y + 1);
        dfs(board , x + 1, y );
    }
};