class Solution {
    public int maxProfit(int[] prices) {
        int minv = Integer.MAX_VALUE;
        int res = 0;
        for ( int p : prices ) {
            minv = Math.min(minv , p);
            res = Math.max(res , p - minv);
        }
        return res;
    }
}