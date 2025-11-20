class Solution {
    Integer[][] dp;

    public int change(int amount, int[] coins) {
        dp = new Integer[amount + 1][coins.length];
        return combos(amount, coins, 0);
    }

    public int combos(int amount, int[] coins, int x) {
        if (amount == 0) return 1;
        if (amount < 0 || x >= coins.length) return 0;

        if (dp[amount][x] != null) return dp[amount][x];

        int ways = 0;

        for (int i = x; i < coins.length; i++) {
            ways += combos(amount - coins[i], coins, i);
        }

        dp[amount][x] = ways;
        return ways;
    }
}
