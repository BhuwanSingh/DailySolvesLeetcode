class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map < int , int> right;
        int l = 0 , r = 0 , res = INT_MAX , n = nums.size();
        right[0] = n;
        for(int i = n - 1; i >= 0 ; i--){
            r += nums[i];
            right[r] = i;
        }
        auto itr = right.find(x);
        if( itr != right.end()){
            res = n - itr->second;
        }
        for(int i = 0 ; i < n ; i++){
            l += nums[i];
            auto itr = right.find(x - l);
            if( itr != right.end() && itr->second > i){
                res = min(res , i + n - itr->second + 1);
            }
        }
        return res != INT_MAX ? res : -1;
    }
};