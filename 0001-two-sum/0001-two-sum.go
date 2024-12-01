func twoSum(nums []int, target int) []int {
    numToIndexMap := make(map[int]int)

    for i , num := range nums{
        diff := target - num 
        if idx, found := numToIndexMap[diff]; found {
            return []int{i , idx}
        }
        numToIndexMap[num] = i
    }
    return nil
}