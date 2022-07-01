class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xr = accumulate(nums.begin() , nums.end() , 0 , bit_xor<int>());
        xr &= -xr;
        vector<int> res = { 0, 0 };
        for(auto i : nums){
            if( i & xr){
                res[0] ^= i;
            } else {
                res[1] ^= i;
            }
        }
        return res;
    }
};