func maxAscendingSum(nums []int) int {
    res, temp := nums[0], nums[0]
    for i := 1 ; i < len(nums) ; i++ {
        if nums[i] > nums[i - 1]{
            temp += nums[i]
        } else {
            temp = 0
            temp += nums[i]
        }
        res = max(res, temp)
    }
    return res
}