func longestCommonPrefix(strs []string) string {
    res := strs[0]
    for i := 1 ; i < len(strs) ; i++ {
        res = commonPrefix(res , strs[i])
    }
    return res
}

func commonPrefix(a string, b string) string {
    i := 0
    for i < len(a) && i < len(b) && a[i] == b[i] {
        i++
    }
    return a[:i]
}