func productExceptSelf(nums []int) []int {
    n := len(nums)
    left, right, res := make( []int , n ), make( []int , n ), make( []int , n )
    left[0] = nums[0]
    right[n - 1] = nums[n - 1]
    
    for i := 1 ; i < n ; i++ {
        left[i] = nums[i] * left[i - 1]
        right[n - i - 1] = nums[n - i - 1] * right[n - i]
    }

    res[0] = right[1]
    res[n - 1] = left[n - 2]
    for i := 1 ; i < n - 1 ; i++ {
        res[i] = left[i - 1] * right[i + 1]
    }

    return res
}