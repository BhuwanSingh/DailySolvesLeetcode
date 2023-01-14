class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size();
        if( n + m != s3.size() ) return false;
        
        vector<vector<bool>> dp(n + 1 , vector<bool>(m + 1));
        
        for(int i = 0; i < n  + 1; i++){
            for(int j = 0; j < m + 1 ; j++){
                if( i == 0 && j == 0){
                    dp[i][j] = true;
                } else if ( i == 0){
                    dp[i][j] = ( s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
                } else if ( j == 0){
                    dp[i][j] = ( s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]);
                } else {
                    dp[i][j] = ( s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) || ( s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]);
                }
            }
        }
        
        return dp[n][m];
    }
};