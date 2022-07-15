class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxval = 0 , minval = INT_MAX;
        for(int i : nums){
            maxval = max(maxval , i);
            minval = min(minval , i);
        }
        return __gcd(minval , maxval);
    }
};