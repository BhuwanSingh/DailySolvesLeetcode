class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 2);        
        for(int i = 1; i < n + 1; i++){
            sums[i] += sums[i - 1] + nums[i - 1];
        }
        int fin = sums[n];
        sums[n + 1] = sums[n];
        for(int i = 1 ; i < n + 1; i++){
            // cout << sums[i] << " ";
            if( sums[i - 1] == fin - sums[i] ) return i - 1;
        }
        // cout << "\n";
        return -1;
    }
};