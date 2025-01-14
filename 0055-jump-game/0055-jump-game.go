func canJump(nums []int) bool {
    i := 0
    n := len(nums)
    for reach := 0 ; i < n && i <= reach; i++ {
        reach = max(i + nums[i] , reach )
    }
    return i == n
}