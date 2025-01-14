func jump(nums []int) int {
    jumps , curEnd , curFarthest := 0, 0, 0
    for i := 0 ; i < len(nums) - 1 ; i++ {
        curFarthest = max(curFarthest, i + nums[i] )
        if i == curEnd {
            jumps++
            curEnd = curFarthest
        }
    }
    return jumps
}