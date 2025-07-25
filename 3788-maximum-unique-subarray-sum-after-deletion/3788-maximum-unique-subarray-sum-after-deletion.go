func maxSum(nums []int) int {
    maxval := math.MinInt
    sum := 0
    uni := map[int]bool{}
    for _, key := range nums {
        if _, ok := uni[key]; !ok {
            if key > 0 {
                sum += key 
            }
            uni[key] = true
        }
        maxval = max(maxval, key)
    }
    if maxval < 0 {
        return maxval
    }
    return sum
}