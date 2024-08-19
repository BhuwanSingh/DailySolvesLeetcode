class Solution {
    public int maxSubArray(int[] nums) {
        int temp = (int)-1e5;
        int res = (int)-1e5;
        for(int i = 0; i < nums.length ; i++){
            temp = Math.max(nums[i] , temp + nums[i]);
            res = Math.max( temp , res);
        }
        return res;
    }
}