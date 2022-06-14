class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>> v(n + 1 , vector<int>(m + 1));
        for(int i = 0; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++){
                if(i == 0 || j == 0){
                    v[i][j] = 0;
                } else if ( word1[i-1] == word2[j-1] ){
                    v[i][j] = 1 + v[i-1][j-1];
                } else {
                    v[i][j] = max(v[i][j-1] , v[i-1][j]);
                }
            }
        }
        return n + m - 2 * v[n][m];
    }
};