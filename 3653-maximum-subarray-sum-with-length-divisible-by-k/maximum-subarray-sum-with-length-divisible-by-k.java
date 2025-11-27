class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long prefixSum = 0;
        long maxSum = Long.MIN_VALUE;
        long []ksum = new long[k];
        for ( int i = 0; i < k ; i++ ) {
            ksum[i] = Long.MAX_VALUE / 2;
        }
        ksum[k - 1] = 0;
        for ( int i = 0; i < n ; i++ ) {
            prefixSum += nums[i];
            maxSum = Math.max(maxSum , prefixSum - ksum[i % k]);
            ksum[i % k] = Math.min(ksum[ i % k] , prefixSum);
        }
        return maxSum;
    }
}