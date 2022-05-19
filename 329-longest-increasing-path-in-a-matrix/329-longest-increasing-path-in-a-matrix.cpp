class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> lp(n , vector<int>(m , 0));
        for(int i = 0; i < n ; i++){
            for(int j = 0 ;  j < m ; j++){
                if(lp[i][j] == 0){
                    lp[i][j] =  dfs(matrix , lp , i , j , -1);   
                }
                // cout << lp[i][j] << " ";
            }
            // cout << "\n";
        }
        int maxval = 0;
        for(auto i : lp){
            for(int j : i){
                maxval = max(maxval , j);
            }
        }
        return maxval;
    }
    
    int dfs(vector<vector<int>>& matrix , vector<vector<int>>& lp , int x , int y , int las ){
        if(x < 0 || x >= lp.size() || y < 0 || y >= lp[0].size() || las >= matrix[x][y] ) return 0;
        if(lp[x][y]) return lp[x][y];
        
        int a = dfs(matrix , lp , x , y - 1 , matrix[x][y]);
        int b = dfs(matrix , lp , x , y + 1 , matrix[x][y]);
        int c = dfs(matrix , lp , x - 1 , y , matrix[x][y]);
        int d = dfs(matrix , lp , x + 1 , y , matrix[x][y]);
        
        lp[x][y] = max( max(a , b) , max(c , d) ) + 1;
        return lp[x][y];

    }
};