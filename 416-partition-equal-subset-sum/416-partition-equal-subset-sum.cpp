class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 , n = nums.size();
        for(int& i : nums) sum += i;
        if( sum % 2 == 1 ) return false;
        int target = sum / 2;
        
        vector<vector<bool>> dp( n + 1, vector<bool>(target + 1 , false));
        
        for(int i = 0; i <= n ; i++){
            for(int j = 0; j <= target ; j++){
                if( i == 0 || j == 0) 
                    dp[i][j] = false;
                else if ( nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else if (nums[i - 1] == j)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            }
        }
        
        return dp[n][target];
    }
};