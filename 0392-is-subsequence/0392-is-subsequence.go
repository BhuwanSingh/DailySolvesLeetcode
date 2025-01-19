func isSubsequence(s string, t string) bool {
    if len(s) == 0 {
        return true
    }
    itr1 , itr2 := 0 , 0
    for itr2 < len(t) {
        if s[itr1] == t[itr2] {
            itr1++
            if itr1 == len(s) {
                return true
            } 
        }
        itr2++;
    }
    return false
}