const mod int64 = 1e9 + 7
var dp[100001][2][3]int64


func f(i , absent , late int ) int64 {
    if absent >= 2 || late >= 3 {
        return 0
    }
    
    if i == 0 {
        return 1
    }
    
    if dp[i][absent][late] != -1 {
        return dp[i][absent][late]
    }
    
    ans := f(i-1 , absent , 0)
    
    if late < 2 {
        ans += f(i - 1 , absent , late + 1)
    }
    
    if absent == 0 {
        ans += f(i - 1 , absent + 1 , 0)
    }
    
    dp[i][absent][late] = ans % mod
    return dp[i][absent][late]
}

func checkRecord(n int) int {
    for i := 0 ; i <= n ; i++{
        for j := 0; j < 2 ; j++ {
            for k := 0 ; k < 3 ; k++{
                dp[i][j][k] = -1
            } 
        }
    }
    return int(f(n , 0, 0))
}