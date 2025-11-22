class Solution {
    public int maxSubArray(int[] nums) {
        int temp = -100000;
        int res = -100000;
        for ( int i = 0; i < nums.length ; i++) {
            temp = Math.max( nums[i] , temp + nums[i]);
            res = Math.max(temp , res);
        }
        return res;
    }
}