func longestCommonPrefix(words []string) []int {
    n := len(words)
    res := make([]int, n)
    if n <= 2 {
        return res
    }

    getLongCommonPrefix := func(s1 , s2 string) int {
        minLen := len(s1)
        if len(s2) < minLen {
            minLen = len(s2)
        }
        for i := 0 ; i < minLen; i++ {
            if s1[i] != s2[i] {
                return i
            }
        }
        return minLen
    }

    prefix := make([]int, n - 1)
    biggest := [3]int{} // to make the array of the largest three.

    for i := 0; i < n - 1; i++ {
        length := getLongCommonPrefix(words[i], words[i + 1])
        prefix[i] = length

        if length > biggest[0] {
            biggest[2] = biggest[1]
            biggest[1] = biggest[0]
            biggest[0] = length
        } else if length > biggest[1] {
            biggest[2] = biggest[1]
            biggest[1] = length
        } else if length > biggest[2] {
            biggest[2] = length
        }
    }

    if prefix[0] == biggest[0] {
        res[0] = biggest[1] // prefix is the largest so take the second largest
    } else {
        res[0] = biggest[0] // prefix is not the largest so take the largest already.
    }

    if prefix[n - 2] == biggest[0] {
        res[n - 1] = biggest[1]
    } else {
        res[n - 1] = biggest[0]
    }

    for i := 1 ; i < n - 1 ; i++ {
        remove1 := prefix[i] // prefix with the one ahead
        remove2 := prefix[i - 1] // prefix with the one before

        if remove2 > remove1 {
            remove1, remove2 = remove2, remove1 // making remove1 the largest.
        }

        maxLen := 0
        if remove1 != biggest[0] {
            maxLen = biggest[0]
        } else if remove2 != biggest[1] {
            maxLen = biggest[1]
        } else {
            maxLen = biggest[2]
        }

        maxLen = max(maxLen, getLongCommonPrefix(words[i - 1] , words[i + 1]) )
        res[i] = maxLen
    }
    return res
}

func max(a , b int ) int {
    if a > b {
        return a
    }
    return b
}