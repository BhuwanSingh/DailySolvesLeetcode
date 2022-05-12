class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        
        if(n + m != o) return false;
        
        vector<vector<bool>> dp(n + 1 , vector<bool>(m + 1 , false));
        dp[0][0] = true;
        for(int i = 0; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++){
                if(i == 0 && j == 0){
                    dp[i][j] == true;
                } else if ( i == 0 ){
                    dp[i][j] = ( dp[i][j - 1] && s2[j-1] == s3[i+j-1] ); 
                } else if ( j == 0 ){
                    dp[i][j] = ( dp[i - 1][j] && s1[i-1] == s3[i+j-1] );
                } else {
                    dp[i][j] = ( dp[i][j - 1] && s2[j-1] == s3[i+j-1] ) || ( dp[i - 1][j] && s1[i-1] == s3[i+j-1] );
                }
                // cout << dp[i][j] << " ";
            }
            // cout << "\n";
        }
        
        return dp[n][m];
    }
};