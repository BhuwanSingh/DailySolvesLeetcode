class Solution {
public:
    int dp[20001][201];
    bool canPartition(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        int n = nums.size() , sum;
        sum = accumulate(nums.begin() , nums.end() , 0);
        if( sum % 2 != 0) return false;
        int target = sum / 2;
        return combos(nums , target , 0);
    }
    
    int combos(vector<int> nums , int target , int x){
        if( target == 0 ) return 1;
        if( x >= nums.size()) return 0;
        
        if( dp[target][x] != -1)
            return dp[target][x];
        
        if( nums[x] <= target )
            dp[target][x] = combos(nums , target - nums[x] , x + 1) || combos(nums , target , x + 1);
        else
            dp[target][x] = combos(nums , target , x + 1);
        
        return dp[target][x];
    }
};