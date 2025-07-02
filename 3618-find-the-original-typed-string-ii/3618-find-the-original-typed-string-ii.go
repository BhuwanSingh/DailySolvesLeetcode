func possibleStringCount(word string, k int) int {
    const mod = 1e9 + 7
    if len(word) == 0 {
        return 0
    }

    groups := []int{}
    count := 1
    for i := 1 ; i < len(word) ; i++ {
        if word[i] == word[i - 1]{
            count++
        } else {
            groups = append(groups, count)
            count = 1
        }
    }
    groups = append(groups, count)

    total := 1
    for _, num := range groups {
        total = (total * num) % mod
    }
    if k <= len(groups) {
        return total
    }

    dp := make([]int, k)
    dp[0] = 1
    for _, num := range groups {
        newDP := make([]int, k)
        sum := 0
        for s := 0 ; s < k ; s++ {
            if s > 0 {
                sum = (sum + dp[s - 1]) % mod
            }
            if s > num {
                sum = (sum - dp[s - num - 1] + mod ) % mod
            }
            newDP[s] = sum
        }
        dp = newDP
    }
    invalid := 0
    for s := len(groups); s < k ; s++ {
        invalid = (invalid + dp[s]) % mod
    }
    return (total - invalid + mod) % mod
}