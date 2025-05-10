func findDisappearedNumbers(nums []int) []int {
    for i := range nums {
        if nums[ abs(nums[i]) - 1] > 0 {
            nums[ abs(nums[i]) - 1] *= -1
        }
    }

    res := []int{}
    for i := range nums {
        if nums[i] > 0 {
            res = append(res , i  + 1)
        }
    }
    return res
}

func abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}