func canPartition(s string, target int) bool {
	if s == "" {
		return target == 0
	}
	if target < 0 {
		return false
	}

	for i := 0; i < len(s); i++ {
		leftStr := s[:i+1]
		rightStr := s[i+1:]

		leftNum, _ := strconv.Atoi(leftStr) // Assume valid as per problem constraints

		if canPartition(rightStr, target-leftNum) {
			return true
		}
	}

	return false
}

func punishmentNumber(n int) int {
	sum := 0
	for num := 1; num <= n; num++ {
		sqr := num * num
		strSqr := strconv.Itoa(sqr)
		if canPartition(strSqr, num) {
			sum += sqr
		}
	}
	return sum
}