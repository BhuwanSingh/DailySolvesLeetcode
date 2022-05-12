class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0];
        int res = temp;
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            temp = max(temp + nums[i] , nums[i]);
            res = max(res , temp);
        }
        return res;
    }
};