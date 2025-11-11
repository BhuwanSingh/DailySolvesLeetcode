func findMaxForm(strs []string, m int, n int) int {
    dp := make([][]int, m + 1)
    for i := range dp {
        dp[i] = make([]int, n + 1)
    }

    countZerosOnes := func(s string) (zeros, ones int) {
        for _, ch := range s {
            if ch == '0' {
                zeros++
            } else {
                ones++
            }
        }
        return
    }

    for _, s := range strs {
        z, o := countZerosOnes(s)
        for i := m ; i >= z ; i-- {
            for j := n ; j >= o ; j-- {
                if dp[i - z][j - o] + 1 > dp[i][j] {
                    dp[i][j] = 1 + dp[i - z][j - o]
                }
            }
        }
        // for i := range dp {
        //     fmt.Println(dp[i])
        // }
        // fmt.Println()
    }

    return dp[m][n]
}