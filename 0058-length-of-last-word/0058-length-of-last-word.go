func lengthOfLastWord(s string) int {
    s = strings.TrimSpace(s)
    return len(s) - strings.LastIndex(s, " ") - 1
}
