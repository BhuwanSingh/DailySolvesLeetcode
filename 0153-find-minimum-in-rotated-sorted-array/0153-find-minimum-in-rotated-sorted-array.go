func findMin(nums []int) int {
    left, right := 0, len(nums)-1

    for left < right {
        mid := left + (right-left)/2

        if nums[mid] > nums[right] {
            // Minimum must be to the right of mid
            left = mid + 1
        } else {
            // Minimum is at mid or to the left of mid
            right = mid
        }
    }

    return nums[left]
}
