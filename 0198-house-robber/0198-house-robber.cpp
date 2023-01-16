class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1 , 0);
        
        for(int i = 1 ; i < n + 1 ; i++){
            dp[i] = max( dp[i - 1] , nums[i - 1] + (i > 1 ? dp[i - 2] : 0) );
        }
        
        return max( dp[n] , dp[n - 1]);
    }
};