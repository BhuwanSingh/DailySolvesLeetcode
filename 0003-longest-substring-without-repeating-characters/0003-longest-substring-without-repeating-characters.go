func lengthOfLongestSubstring(s string) int {
    temp := make(map[byte]int)
    var l , r , res int = 0 , 0 , 0
    n := len(s)
    for r < n {
        // fmt.Print(l ,"," , r , " ")
        if temp[ s[r] ] == 0{
            temp[ s[r] ] += 1
            r++
        } else {
            for temp[ s[r] ] != 0 {
                temp[ s[l] ] -= 1
                l++
            }
        }
        res = int(math.Max(float64(res) , float64(r - l) ))
    }
    // fmt.Print("\n")
    return res
}