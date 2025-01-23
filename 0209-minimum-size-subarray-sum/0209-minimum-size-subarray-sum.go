func minSubArrayLen(target int, nums []int) int {
	left, sum, res := 0, 0, math.MaxInt32

	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		for sum >= target {
			res = int(math.Min(float64(res), float64(i-left+1)))
			sum -= nums[left]
			left++
		}
	}

	if res == math.MaxInt32 {
		return 0
	}
	return res
}