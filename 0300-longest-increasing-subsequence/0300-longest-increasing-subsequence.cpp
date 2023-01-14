class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 0; i < n ; i++){
            auto itr = lower_bound( v.begin() , v.end() , nums[i]);
            if( itr == v.end()){
                v.push_back( nums[i]);
            } else {
                v[itr - v.begin()] = nums[i];
            }
        }
        return v.size();
    }
};