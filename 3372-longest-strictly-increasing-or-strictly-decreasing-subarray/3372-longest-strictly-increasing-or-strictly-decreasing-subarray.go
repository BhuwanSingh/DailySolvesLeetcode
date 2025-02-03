func Max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func longestMonotonicSubarray(nums []int) int {
    n := len(nums)
    inc, dec := make([]int, n), make([]int, n)

    for i := 0; i < n; i++ {
        inc[i] = 1
        dec[i] = 1
    }

    for i := 1; i < n; i++ {
        if nums[i] > nums[i - 1] {
            inc[i] = inc[i - 1] + 1
        }
        if nums[i] < nums[i - 1] {
            dec[i] = dec[i - 1] + 1
        }
    }
    ans := 0
    for i := 0; i < n; i++ {
        ans = Max (ans, inc[i])
        ans = Max (ans, dec[i])
    }
    return ans
}