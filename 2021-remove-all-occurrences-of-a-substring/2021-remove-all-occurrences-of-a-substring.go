func removeOccurrences(s string, part string) string {
	partLen := len(part)
	for {
		index := strings.Index(s, part) // find all occurances of part string in s
		if index == -1 {
			break
		}
		s = s[:index] + s[index+partLen:]
	}

	return s
}