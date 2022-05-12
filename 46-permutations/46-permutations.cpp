class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        combos(nums , res , 0);
        return res;
    }
    
    void combos( vector<int>& nums , vector<vector<int>>& res , int itr){
        if(itr >= nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = itr ; i < nums.size() ; i++){
            swap(nums[itr] , nums[i]);
            combos(nums , res , itr + 1);
            swap(nums[itr] , nums[i]);
        }
    }
};
