func canPartition(nums []int) bool {
    target := 0
    for _, val := range nums {
        target += val
    }
    if target%2 != 0 {
        return false
    }
    target /= 2

    dp := make([][]int, target+1)
    for i := range dp {
        dp[i] = make([]int, len(nums)+1)
    }

    return check(nums, target, 0, dp)
}

func check(nums []int, target, curr int, dp [][]int) bool {
    if target == 0 {
        return true
    }
    if curr == len(nums) || target < 0 {
        return false
    }
    if dp[target][curr] != 0 {
        return dp[target][curr] == 1
    }

    include := check(nums, target-nums[curr], curr+1, dp)
    exclude := check(nums, target, curr+1, dp)

    if include || exclude {
        dp[target][curr] = 1
        return true
    }
    
    dp[target][curr] = -1
    return false
}
