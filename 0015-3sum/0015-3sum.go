func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    n := len(nums)
    
    var res [][]int
    
    for i := 0 ; i < n - 2 ; i++ {
        if i > 0 && nums[i] == nums[i - 1]{
            continue
        }
        l , r := i + 1 , n - 1
        for l < r {
            sum := nums[i] + nums[l] + nums[r]
            if sum  < 0 {
                l++
            } else if sum > 0 {
                r--
            } else {
                res = append( res , []int{nums[i] , nums[l] , nums[r]})  
                for l < r && nums[l] == nums[l + 1] {
                    l++
                }
                for l < r && nums[r] == nums[r - 1] {
                    r--
                }
                l++
                r--
            }
        }
    }
    
    return res 
}