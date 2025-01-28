func minWindow(s string, t string) string {
    if len(s) < len(t) {
        return ""
    }

    tFreq := make(map[byte]int)
    for i := 0; i < len(t); i++ {
        tFreq[t[i]]++
    }

    windowFreq := make(map[byte]int)
    left, right := 0, 0
    matched := 0
    minLen := math.MaxInt32
    start := 0

    for right < len(s) {
        char := s[right]
        windowFreq[char]++

        if tFreq[char] > 0 && windowFreq[char] <= tFreq[char] {
            matched++
        }

        for matched == len(t) {
            if right - left + 1 < minLen {
                minLen = right - left + 1
                start = left
            }
            leftChar := s[left]
            windowFreq[leftChar]--

            if tFreq[leftChar] > 0 && windowFreq[leftChar] < tFreq[leftChar] {
                matched--
            }
            left++
        }
        right++
    }
    if minLen == math.MaxInt32 {
        return ""
    }
    return s[start : start + minLen]
}