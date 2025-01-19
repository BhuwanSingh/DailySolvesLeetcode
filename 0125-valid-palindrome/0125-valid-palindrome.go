func isPalindrome(s string) bool {
    left, right := 0 , len(s) - 1

    for left < right {
        for left < len(s) && (!unicode.IsLetter(rune(s[left])) && !unicode.IsNumber(rune(s[left]))) {
            left++
        }
        for right >= 0 && (!unicode.IsLetter(rune(s[right])) && !unicode.IsNumber(rune(s[right]))) {
            right--
        }
        if left < len(s) && right >= 0 &&  unicode.ToLower(rune(s[left])) != unicode.ToLower(rune(s[right])) {
            return false
        }
        left++
        right--
    }
    return true
}