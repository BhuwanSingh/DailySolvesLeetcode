class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        long[][] dp = new long[n + 1][amount + 1];

        for ( int i = 0 ; i <= n ; i++) {
            dp[i][0] = 1;
        }

        for ( int i = 1 ; i <= amount ; i++) {
            dp[0][i] = 0;
        }

        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= amount ; j++ ) {
                dp[i][j] = dp[i - 1][j];
                if ( j >= coins[i - 1] ) {
                    dp[i][j] += + dp[i][j - coins[i - 1]];
                }
            }
        }

        // for(long[] x : dp) {
        //     for (long y : x) {
        //         System.out.print(y + " ");
        //     }
        //     System.out.println();
        // }

        return (int)dp[n][amount];
    }
}