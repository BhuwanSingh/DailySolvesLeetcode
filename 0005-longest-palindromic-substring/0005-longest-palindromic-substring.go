func longestPalindrome(s string) string {
    result := ""

    for i := 0 ; i < len(s) ; i++ {
        left := i
        right := i
        for left >= 0 && right < len(s) {
            if s[left] == s[right] {
                if len(s[left:right + 1]) > len(result){
                    result = s[left:right + 1]
                }
            } else {
                break
            }
            left--
            right++
        }
    }

    for i := 1 ; i < len(s) ; i++ {
        left := i - 1
        right := i
        for left >= 0 && right < len(s) {
            if s[left] == s[right] {
                if len(s[left:right + 1]) > len(result){
                    result = s[left:right + 1]
                }
            } else {
                break
            }
            left--
            right++
        }
    }

    return result
}