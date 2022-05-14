class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map< int , vector<int>> ms;
        for(int i = 0; i < nums.size() ; i++){
            ms[nums[i]].push_back(i);
        }
        
        for(int i = 0; i < nums.size() ; i++){
            auto itr = ms.find( target - nums[i]);
            if(itr != ms.end()){
                for(auto j : itr->second){
                    if( j != i) return {i , j};
                }
            }
        }
        return {};
    }
};