func smallestNumber(n int) int {
    var pow, res float64 = 0 , 0
    temp := float64(n)
    for res < temp {
        res = math.Pow( float64(2), pow) - 1
        if res >= temp {
            return int(res)
        }
        pow++
    }
    return -1
}