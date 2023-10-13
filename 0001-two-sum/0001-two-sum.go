func twoSum(nums []int , target int ) []int{
    m := make(map[int]int , len(nums))
    var res []int
    for i , num := range nums {
        complement := target - num
        if j , ok := m[complement]; ok {
            return append(res , i , j)
        }
        m[num] = i
    }
    return res
}