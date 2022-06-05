class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map< int, int> um;
        for(int j = 0; j < nums.size() ; j++){
            int i = nums[j];
            auto itr = um.find(target - i);
            if( itr != um.end() && itr->first + i == target){
                return { itr->second , j};
            }
            um[i] = j;
        }
        return {};
    }
};