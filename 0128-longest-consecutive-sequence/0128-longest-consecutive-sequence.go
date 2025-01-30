func longestConsecutive(nums []int) int {
    numSet := make(map[int]bool)
    for _, num := range nums {
        numSet[num] = true
    }

    best := 0
    for num := range numSet {
        if !numSet[num-1] { // Start of a new sequence
            y := num + 1
            for numSet[y] {
                y++
            }
            best = max(best, y-num)
        }
    }
    return best
}