class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> v;
        for(int i : nums){
            v.push_back(nums[i]);
        }
        return v;
    }
};