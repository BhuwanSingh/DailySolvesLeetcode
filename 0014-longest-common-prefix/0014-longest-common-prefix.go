func longestCommonPrefix(strs []string) string {
    res := strs[0]
    
    for _ , elem := range strs {
        res = lcs(res , elem)
    }
    
    return res
}

func lcs(str1 string , str2 string ) string {
    i := 0
    
    for i < len(str1) && i < len(str2) && str1[i] == str2[i] {
        i++
    }
    
    if i < 0 {
        return ""
    }
    
    return str1[:i]
    
}