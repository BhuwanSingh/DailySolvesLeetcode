func strStr(haystack string, needle string) int {
    h := len(haystack)
    n := len(needle)
    switch {
        case n == 0:
            return 0
        case n == 1:
            for i := 0 ; i < h ; i++ {
                if string(haystack[i]) == needle {
                    return i
                }
            }
        case n == h:
            if haystack == needle {
                return 0
            }
        case n > h:
            return -1
        default:
            for i := 0 ; i < h - n + 1 ; i++ {
                if haystack[i : i + n] == needle {
                    return i
                }
            }
    }
    return -1
}