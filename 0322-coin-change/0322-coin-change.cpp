class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() , m = amount;
        vector<int> dp(m + 1 , m + 1);
        dp[0] = 0;
        for(int i = 1; i <= m ; i++){
            for(int j = 0 ; j < coins.size() ; j++){
                if( i >= coins[j]){
                    dp[i] = min(dp[i] , dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[m] > m ? -1 : dp[m];
    }
};