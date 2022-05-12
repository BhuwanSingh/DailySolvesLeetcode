class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        combos(nums , res , 0);
        return res;
    }
    void combos( vector<int> nums , vector<vector<int>>& res , int itr){
        if(itr == ( nums.size() - 1) ){
            res.push_back(nums);
            return;
        }
        for(int i = itr ; i < nums.size() ; i++){
            if( i != itr && nums[i] == nums[itr]) continue;
            swap(nums[itr] , nums[i]);
            combos(nums , res , itr + 1);
            // swap(nums[itr] , nums[i]);
        }
        return;
    }
};

