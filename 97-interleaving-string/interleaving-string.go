func isInterleave(s1 string, s2 string, s3 string) bool {
    n , m , o := len(s1) , len(s2) , len(s3)
    if o != n + m {
        return false
    }

    table := make( [][]bool , n + 1)
    for i := range table {
        table[i] = make([]bool, m + 1)
    }
    
    for i := 0 ; i <= n ; i++ {
        for j := 0 ; j <= m ; j++ {
            if i == 0 && j == 0 {
                table[i][j] = true
            } else if i == 0 {
                table[i][j] = table[i][j - 1] && s2[j - 1] == s3[i + j - 1]
            } else if j == 0 {
                table[i][j] = table[i - 1][j] && s1[i - 1] == s3[i + j - 1]
            } else {
                table[i][j] = ( table[i][j - 1] && s2[j - 1] == s3[i + j - 1] ) || ( table[i - 1][j] && s1[i - 1] == s3[i + j - 1] )
            }
        }
    }
    return table[n][m]
}