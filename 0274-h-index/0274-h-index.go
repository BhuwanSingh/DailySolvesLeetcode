func hIndex(citations []int) int {
    sort.Ints(citations)
    tot := 0
    for i := len(citations) - 1 ; i >= 0 ; i-- {
        if citations[i] > tot{
            tot++
        } else {
            break
        }
    }
    return tot
}