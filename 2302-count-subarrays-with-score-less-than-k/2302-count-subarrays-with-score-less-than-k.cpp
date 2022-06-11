class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0 , curr = 0;
        for(int i = 0 , j = 0 ; j < nums.size() ; j++){
            curr += nums[j];
            while( curr * (j - i + 1 ) >= k){
                curr -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};