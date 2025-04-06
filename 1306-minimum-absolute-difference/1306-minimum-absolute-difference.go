func minimumAbsDifference(arr []int) [][]int {
    slices.Sort(arr)
    diff := math.MaxInt
    for i := 1 ; i < len(arr) ; i++ {
        diff = min(diff, arr[i] - arr[i-1])
    }
    res := [][]int{}
    for i := 1 ; i < len(arr) ; i++ {
        if arr[i] - arr[i - 1] == diff {
            res = append(res , []int{arr[i-1], arr[i]} )
        }
    }
    return res
}