class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            if( grid[i][0] == 1) continue;
            for(int j = 0 ; j < m ; j++){
                grid[i][j] = 1 - grid[i][j];
            }
        }
        int res = 0;
        for(int j = m - 1; j >= 0; j--){
            int temp = 0;
            for(int i = 0 ; i < n ; i++){
                if( grid[i][j] == 1) temp++;
            }
            res += max( temp , n - temp ) * ( 1 << (m - j - 1) ) ;
        }
        return res;
    }
};