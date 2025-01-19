func convert(s string, numRows int) string {
    if numRows <= 1 || len(s) <= numRows {
        return s
    }

    sb := make([]string, numRows)

    i := 0
    lenS := len(s)

    for i < lenS {
        for idx := 0 ; idx < numRows && i < lenS ; idx++ {
            sb[idx] += string(s[i])
            i++
        }
        for idx := numRows - 2 ; idx >= 1 && i < lenS ; idx-- {
            sb[idx] += string(s[i])
            i++
        }
    }

    result := sb[0]
    for idx := 1 ; idx < numRows ; idx++ {
        result += sb[idx]
    }
    return result
}