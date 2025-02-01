func merge(intervals [][]int) [][]int {
    sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

    var res [][]int
    res = append(res , intervals[0])
    for i := 0 ; i < len(intervals) ; i++ {
        cur := res[len(res) - 1]
        if cur[1] < intervals[i][0] {
            res = append(res , intervals[i])
        } else {
            cur[1] = max(cur[1], intervals[i][1])
        }
    }
    return res
}