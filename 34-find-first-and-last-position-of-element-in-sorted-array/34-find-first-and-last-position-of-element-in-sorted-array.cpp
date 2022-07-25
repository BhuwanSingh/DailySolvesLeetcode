class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itr1 = lower_bound( nums.begin() , nums.end() , target);
        auto itr2 = upper_bound( nums.begin() , nums.end() , target);
        if( itr1 == nums.end() ) return { -1 , -1};
        itr2--;
        if( itr2 - itr1 < 0 ) return { -1 , -1};
        else return { int(itr1 - nums.begin()) , int(itr2 - nums.begin())};
    }
};