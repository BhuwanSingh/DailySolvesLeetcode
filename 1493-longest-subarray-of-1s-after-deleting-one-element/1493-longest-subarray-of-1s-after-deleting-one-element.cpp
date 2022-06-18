class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int temp = 0 , res = 0 , l = 0 , n = nums.size() , zeros = 0;
        for(int i = 0; i < n ; i++){
            if( nums[i] == 0) zeros++;
            while( zeros > 1 ){
                if(nums[l] == 0) zeros--;
                l++;
            }
            res = max(res , i - l + 1);
        }
        return res - 1;
    }
};