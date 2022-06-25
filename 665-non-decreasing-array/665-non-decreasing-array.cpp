class Solution {
public:
    int n;
    bool checkPossibility(vector<int>& nums) {
        this->n = nums.size();
        return ci(nums) || cd(nums);
    }
    
    bool ci(vector<int>& nums){
        int maxval = nums[0];
        bool h = false;
        for(int i = 1; i < n ; i++){
            maxval = max(maxval , nums[i - 1]);
            if( nums[i] < maxval){
                if(!h) h = true;
                else return false;
            }
        }
        return true;
    }
    
    bool cd(vector<int>& nums){
        bool h = false;
        int minval = nums[n - 1];
        for(int i = n - 2; i >= 0 ; i--){
            minval = min(minval , nums[i + 1]);
            if( nums[i] > minval){
                if(!h) h = true;
                else return false;
            }
        }
        return true;
    }
};