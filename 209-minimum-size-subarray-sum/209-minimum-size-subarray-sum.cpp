class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size()  , l = 0 , r = 0 , sum = 0 , res = INT_MAX;
        while( r < n && sum < target){
            sum += nums[r];
            while(l <= r && sum >= target){
                sum -= nums[l];
                res = min(res , r - l + 1);
                l++;
            }
            r++;
        }
        return res != INT_MAX ? res : 0;
    }
};