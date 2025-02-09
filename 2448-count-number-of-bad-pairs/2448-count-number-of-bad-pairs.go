func countBadPairs(nums []int) int64 {
    diffs := make(map[int]int)

    for i, val := range nums {
        temp := i - val
        diffs[temp]++
    }

    goodPairs := 0
    totalPairs := (len(nums) * ( len(nums) - 1 )) / 2

    for _ , value := range diffs {
        if value > 1 {
            goodPairs +=  ( value * (value - 1 ) ) / 2
        }
        // fmt.Println(goodPairs)
    }

    return int64(totalPairs - goodPairs)
}