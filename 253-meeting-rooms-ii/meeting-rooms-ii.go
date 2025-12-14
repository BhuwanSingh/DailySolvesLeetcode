func minMeetingRooms(intervals [][]int) int {
    start := []int{}
    end := []int{}

    for _, meets := range intervals {
        start = append(start, meets[0])
        end = append(end, meets[1])
    }

    sort.Ints(start)
    sort.Ints(end)

    i , j := 0 , 0

    var count int = 0
    var res int = 0

    for i < len(intervals) && j < len(intervals) {
        if start[i] < end[j] {
            count++
            res = int(math.Max( float64(count), float64(res)))
            i++
        } else if start[i] == end[j] {
            i++
            j++
        } else {
            count--
            j++
        }
    }

    return res
}