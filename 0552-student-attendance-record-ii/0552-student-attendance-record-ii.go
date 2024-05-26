func checkRecord(n int) int {
    if n == 1{
        return 3
    } else if n == 2 {
        return 8
    } else if n == 3 {
        return 19
    }
    
    const mod = 1000000007
    dp := make([]int , n + 1)
    dp[0] , dp[1] , dp[2] , dp[3] = 1 , 2, 4 , 7
    
    for i := 4; i <= n ; i++ {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod
    }
    
    withA := 0
    
    for i := 0; i < n ; i++ {
        withA = (withA + dp[i]*dp[n - 1 - i] ) % mod
    }
    
    return (dp[n] + withA) % mod
}