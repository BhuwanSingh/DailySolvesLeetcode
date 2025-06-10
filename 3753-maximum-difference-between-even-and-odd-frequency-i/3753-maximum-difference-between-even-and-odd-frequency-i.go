func maxDifference(s string) int {
	cnt := make([]int, 26)
	a1, a2 := 0, math.MaxInt
	for i := 0; i < len(s); i++ {
		cnt[s[i]-'a']++
	}
	for i := 0; i < 26; i++ {
		if cnt[i]%2 == 1 {
			a1 = max(a1, cnt[i])
		} else if cnt[i] != 0 {
			a2 = min(a2, cnt[i])
		}
	}
	return a1 - a2
}