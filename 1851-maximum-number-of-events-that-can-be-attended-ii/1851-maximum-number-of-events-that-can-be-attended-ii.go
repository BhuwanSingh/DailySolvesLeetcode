func maxValue(events [][]int, k int) int {
    sort.Slice( events, func(a , b int) bool {
        if events[a][0] == events[b][0] {
            return events[a][1] < events[b][1]
        }
        return events[a][0] < events[b][0]
    })
    n := len(events)
    dp := make([][]int, n + 1)
    for i := range dp {
        dp[i] = make([]int, k + 1)
            for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return solve(dp, events, n , 0 , k)
}

func solve( dp [][]int, events [][]int, n, pos, k int) int {
    i := 0
    if pos >= n || k == 0 {
        return 0
    }
    if dp[pos][k] != -1 {
        return dp[pos][k]
    }
    for i = pos + 1 ; i < n ; i++ {
        if events[i][0] > events[pos][1] {
            break
        }
    }
    dp[pos][k] = max(solve(dp, events, n, pos+1, k), events[pos][2] + solve(dp, events, n, i, k-1))
    return dp[pos][k]
}