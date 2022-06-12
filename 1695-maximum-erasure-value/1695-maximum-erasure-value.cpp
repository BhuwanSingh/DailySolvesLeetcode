class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size() , l = 0;
        unordered_set<int> um;
        int temp = 0 , res = 0;
        for(int i = 0; i < n ; i++){
            while( um.find(nums[i]) != um.end()){
                um.erase(nums[l]);
                temp -= nums[l];
                l++;
            }
            temp += nums[i];
            res = max(temp  , res);
            um.insert(nums[i]);
        }
        return res;
    }
};