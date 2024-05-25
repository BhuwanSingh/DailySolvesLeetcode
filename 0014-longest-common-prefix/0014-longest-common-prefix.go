func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }

    prefix := strs[0]

    for _, str := range strs[1:] {
        prefix = commonPrefix(prefix, str)
        if prefix == "" {
            break
        }
    }

    return prefix
}

func commonPrefix(str1, str2 string) string {
    minLength := min(len(str1), len(str2))

    i := 0
    for i < minLength && str1[i] == str2[i] {
        i++
    }

    return str1[:i]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
