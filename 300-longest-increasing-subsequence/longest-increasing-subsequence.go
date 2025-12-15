func lengthOfLIS(nums []int) int {
    lis := []int{nums[0]}

    for i := 1 ;  i < len(nums) ; i++ {
        num := nums[i]
        if lis[len(lis) - 1] < num {
            lis = append(lis, num)
        } else {
            itr := sort.Search( len(lis) , func(j int) bool {
                return lis[j] >= num
            })
            lis[itr] = num
        }
    }

    return len(lis)
}