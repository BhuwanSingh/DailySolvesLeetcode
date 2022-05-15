class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            if( v.empty() || nums[i] > v.back()){
                v.push_back(nums[i]);
            } else {
                auto itr = lower_bound( v.begin() , v.end() , nums[i]);
                *itr = nums[i];
            }
        }
        return v.size();
    }
};