func letterCombinations(digits string) []string {
    if digits == "" {
		return []string{}
	}
	
	mapping := []string{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	ans := []string{""}
	
	for len(ans[0]) != len(digits) {
		remove := ans[0]
		ans = ans[1:]
		mapIndex := digits[len(remove)] - '0'
		for _, c := range mapping[mapIndex] {
			ans = append(ans, remove+string(c))
		}
	}
	
	return ans
}