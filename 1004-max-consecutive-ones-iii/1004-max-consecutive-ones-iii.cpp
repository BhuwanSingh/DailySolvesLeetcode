class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0 , temp = 0 , res = 0 , l = 0 , n = nums.size();
        for(int i = 0; i < n ; i++){
            if( nums[i] == 0) zeros++;
            while(zeros > k){
                if( nums[l] == 0) {
                    zeros--;
                }
                l++;
            }
            if( nums[i] == 1 || zeros) temp = i - l + 1;
            res = max(res , temp);            
        }
        return res;
    }
};