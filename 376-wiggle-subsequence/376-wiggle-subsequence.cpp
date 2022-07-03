class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size() , pu  = 1 , pd = 1 , cu = 0 , cd = 0;
        if(n == 1) return 1;
        for(int i = 1 ; i < n ; i++){
            if( nums[i] > nums[i-1]){
                cu = pd + 1;
                cd = pd;
            } else if ( nums[i] < nums[i - 1]){
                cd = pu + 1;
                cu = pu;
            } else {
                cu = pu;
                cd = pd;
            }
            pu = cu;
            pd = cd;
        }
        return max(cu , cd);
    }
};