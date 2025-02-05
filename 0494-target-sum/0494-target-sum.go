func findTargetSumWays(nums []int, target int) int {
    return check(nums, target, 0)
}

func check(nums []int, target int, curr int) int {
    if curr == len(nums) {
        if target == 0 {
            return 1
        } else {
            return 0
        }
    }
    return check(nums, target + nums[curr] , curr + 1) + check(nums, target - nums[curr] , curr + 1)
}