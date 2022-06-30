class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());        
        int n = nums.size() , mid = n / 2 , res = 0;
        for(int i = 0; i < n ; i++){
            res += abs(nums[i] - nums[mid]);
        }
        return res;
    }
};