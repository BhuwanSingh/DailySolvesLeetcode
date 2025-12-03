class Solution {
    public int maxProfit(int[] prices) {
        int res = 0, min_val = prices[0];

        for ( int i = 1 ; i < prices.length ; i++) {
            min_val = Math.min(min_val, prices[i - 1]);
            res = Math.max( res , prices[i] - min_val);
        }
        return res;
    }
}