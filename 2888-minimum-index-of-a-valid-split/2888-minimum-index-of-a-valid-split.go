func minimumIndex(nums []int) int {
    ans := -1
    left := map[int]int{}
    right := map[int]int{}

    for _, num := range nums {
        right[num]++
    }

    for i := 0; i < len(nums); i++ {
        left[nums[i]]++
        right[nums[i]]--

        if left[nums[i]]*2 > (i + 1) && right[nums[i]] * 2 > (len(nums)-i-1) {
            return i
        }
    }

    return ans
}