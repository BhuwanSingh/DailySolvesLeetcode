
func isIsomorphic(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    mapS := make(map[byte]byte)
    mapT := make(map[byte]byte)

    for i := 0; i < len(s); i++ {
        ch1, ch2 := s[i], t[i]

        if val, ok := mapS[ch1]; ok && val != ch2 {
            return false
        }
        if val, ok := mapT[ch2]; ok && val != ch1 {
            return false
        }

        mapS[ch1] = ch2
        mapT[ch2] = ch1
    }

    return true
}