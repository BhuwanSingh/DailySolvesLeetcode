class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if( grid[0][0] == 1 ) return -1;
        int n = grid.size();
        queue< vector<int>> q;
        q.push( {0 , 0});
        grid[0][0] = 1;
        int res = 1;
        while( !q.empty() ){
            int s = q.size();
            for(int i = 0; i < s ; i++){
                vector<int> curr = q.front();
                q.pop();
                grid[curr[0]][curr[1]] = 1;
                if( curr[0] == n - 1 && curr[1] == n - 1 ) return res;
                for( int j = curr[0] - 1 ; j < curr[0] + 2 ; j++){
                    for( int k = curr[1] - 1 ; k < curr[1] + 2 ; k++){
                        if( j >= 0 && j < n && k >= 0 && k < n && grid[j][k] == 0){
                            q.push({j , k});
                            grid[j][k] = 1;
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};