func containsNearbyDuplicate(nums []int, k int) bool {
    mp := map[int]int{}
    for idx, val := range nums {
        if index, found := mp[val]; found && idx - index <= k  {
            return true
        }
        mp[val] = idx
    }
    return false
}