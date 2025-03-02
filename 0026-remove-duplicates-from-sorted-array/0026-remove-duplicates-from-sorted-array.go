func removeDuplicates(nums []int) int {
    ln := len(nums)
    if ln <= 1 {
        return ln
    }
    j := 0
    for i := 1; i < ln; i++ {
        if nums[j] != nums[i] {
            j++
            nums[j] = nums[i]
        }
    }
    return j + 1
}