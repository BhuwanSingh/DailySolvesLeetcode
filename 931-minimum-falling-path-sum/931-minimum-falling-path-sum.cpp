class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = 1e5;
        for(int i = 0 ; i < n ; i++){
            res = min(res , path(matrix , i));
            // res = min(res , temp);
            // cout << "\n";
        }    
        return res;
    }
    
    int path(vector<vector<int>> ms , int x){
        int start = x , end = x;
        int n = ms.size();
        vector<vector<int>> matrix(n , vector<int>(n , 1e5));
        int level = 0;
        for(int i = 0; i < n ; i++) matrix[0][i] = ms[0][i];
        while( level < n - 1 ){
            for(int i = start ; i <= end ; i++){
                if( i > 0 ) matrix[level + 1][i - 1] = min(matrix[level + 1][i - 1] , ms[level + 1][i - 1] + matrix[level][i] );
                matrix[level + 1][i] = min(matrix[level + 1][i] , ms[level + 1][i] + matrix[level][i]);
                if( i < n - 1) matrix[level + 1][i + 1] = min(matrix[level + 1][i + 1] , ms[level + 1][i + 1] + matrix[level][i]);
            }
            if( start > 0 ) start--;
            if( end < n - 1) end++;
            level += 1;
        }
        int res = 1e5;
        // for(auto i : matrix){
        //     for(auto j : i){
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        for(int i = 0; i < n ; i++){
            res = min(res , matrix[n - 1][i]);
        }
        return res;
    }
};