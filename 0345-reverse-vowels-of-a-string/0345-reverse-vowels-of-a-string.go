func reverseVowels(str string) string {
    left, right := 0, len(str) - 1
    s := []byte(str)
    vowels := map[byte]bool{
        'a' : true,
        'e' : true,
        'i' : true,
        'o' : true,
        'u' : true,
        'A' : true,
        'E' : true,
        'I' : true,
        'O' : true,
        'U' : true,
    }

    for left < right {
        for left < right {
            if _, ok := vowels[s[left]]; ok {
                break
            }
            left++
        }
        for left < right {
            if _, ok := vowels[s[right]]; ok {
                break
            }
            right--
        }
        // fmt.Println(left, " ", right)
        s[left], s[right] = s[right], s[left]
        left++
        right--
    }
    return string(s)
}