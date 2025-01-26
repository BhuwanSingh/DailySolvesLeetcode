func wordPattern(pattern string, s string) bool {
    codes := make(map[string]byte)
    used := make([]bool, 26)
    words := strings.Split(s, " ")
    if len(pattern) != len(words) {
        return false
    }

    for i, word := range words {
        code, ok := codes[word]
        if !ok {
            if used[pattern[i] - 'a'] {
                return false
            }
            used[pattern[i] - 'a'] = true
            codes[word] = pattern[i]
            continue
        }
        if code != pattern[i] {
            return false
        }
    }
    return true
}