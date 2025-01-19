func reverseWords(s string) string {
    n := len(s)
    var result []byte
    var word []byte
    i := n - 1

    for i >= 0 {
        // Skip trailing spaces
        for i >= 0 && s[i] == ' ' {
            i--
        }

        // Collect the current word
        word = nil
        for i >= 0 && s[i] != ' ' {
            word = append([]byte{s[i]}, word...) // Prepend the character
            i--
        }

        // Add the word to the result
        if len(word) > 0 {
            if len(result) > 0 {
                result = append(result, ' ') // Add space between words
            }
            result = append(result, word...)
        }
    }

    return string(result)
}