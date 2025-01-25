func findSubstring(s string, words []string) []int {
    wordLen := len(words[0])
    totalWords := len(words)
    totalLen := wordLen * totalWords
    result := []int{}

    if len(s) < totalLen {
        return result
    }

    wordCount := make(map[string]int)
    for _, word := range words {
        wordCount[word]++
    }

    for i := 0; i < wordLen; i++ {
        left, count := i, 0
        seen := make(map[string]int)
        for j := i; j+wordLen <= len(s); j += wordLen {
            word := s[j : j+wordLen]
            if freq, exists := wordCount[word]; exists {
                seen[word]++
                count++
                for seen[word] > freq {
                    seen[s[left:left+wordLen]]--
                    count--
                    left += wordLen
                }
                if count == totalWords {
                    result = append(result, left)
                }
            } else {
                seen = make(map[string]int)
                count = 0
                left = j + wordLen
            }
        }
    }

    return result
}
