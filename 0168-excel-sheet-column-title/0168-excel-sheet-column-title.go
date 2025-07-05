func convertToTitle(columnNumber int) string {
    res := []byte{}
    for columnNumber > 0 {
        columnNumber--
        rem := columnNumber % 26
        res = append(res, byte('A' + rem))
        columnNumber /= 26
    }
    for left , right := 0 , len(res) - 1 ; left < right; {
        res[left], res[right] = res[right], res[left]
        left++
        right--
    }

    return string(res)
}