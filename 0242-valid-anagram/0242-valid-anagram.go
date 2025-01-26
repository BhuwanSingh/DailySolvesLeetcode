func isAnagram(s string, t string) bool {
    alp := [26]int{}
    for _, val := range s {
        alp[val - 'a']++
    }
    for _, val := range t {
        alp[val - 'a']--
    }
    for _, val := range alp {
        // fmt.Print(val , " ")
        if val != 0 {
            return false
        }
    }
    return true
}