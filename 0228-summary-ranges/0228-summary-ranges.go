func summaryRanges(nums []int) []string {
    if len(nums) == 0 {
        return nil
    }
    var res[] string
    var head int = 0
    for i := range nums{
        if i < len(nums) - 1 && (nums[i] + 1 == nums[i + 1]){
            continue
        }
        if head == i {
            res = append(res , strconv.Itoa(nums[i]))
        } else {
            temp := strconv.Itoa(nums[head]) + "->" + strconv.Itoa(nums[i])
            res = append(res, temp)
        }
        head = i + 1
    }
    return res
}