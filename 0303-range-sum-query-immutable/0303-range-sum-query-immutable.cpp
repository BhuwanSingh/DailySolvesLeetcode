class NumArray {
public:
    vector<int> nums;
    vector<int> sums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        sums.resize(n);
        sums[0] = nums[0];
        for(int i = 1; i < n ; i++){
            sums[i] += sums[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if( left == 0 ) return sums[right];
        return sums[right] - sums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */