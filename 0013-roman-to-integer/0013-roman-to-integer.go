func romanToInt(s string) int {
    m := make(map[byte]int)
    m['I'] = 1
    m['V'] = 5
    m['X'] = 10
    m['L'] = 50
    m['C'] = 100
    m['D'] = 500
    m['M'] = 1000

    ans := 0

    for i := 0 ; i < len(s) ; i++ {
        if i + 1 < len(s) && m[s[i]] < m[s[i + 1]] {
            ans -= m[s[i]]
        } else {
            ans += m[s[i]]
        }
    }
    return ans
}