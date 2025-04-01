func mostPoints(q [][]int) int64 {
    dp := [200001]int64{}

    for i := len(q) - 1; i >= 0; i-- {
        dp[i] = max( int64(q[i][0]) + dp[q[i][1] + i + 1], dp[i + 1])
    }

    return dp[0]
}