func maxProfit(prices []int) int {
	n := len(prices)
	if n == 0 {
		return 0
	}

	// lp[i] = max profit using ONE transaction in range [0..i]
	// rp[i] = max profit using ONE transaction in range [i..n-1]
	lp := make([]int, n)
	rp := make([]int, n)

	lmin := math.MaxInt // minimum price seen so far from left
	rmax := math.MinInt // maximum price seen so far from right

	// Left to right pass
	// Decide best profit if we sell at i (or do nothing)
	for i := 1; i < n; i++ {
		lmin = min(lmin, prices[i-1])           // best buying price so far
		lp[i] = max(lp[i-1], prices[i]-lmin)    // either sell today or keep previous profit
	}

	// Right to left pass
	// Decide best profit if we buy at i (or do nothing)
	for i := n - 2; i >= 0; i-- {
		rmax = max(rmax, prices[i+1])           // best selling price in future
		rp[i] = max(rp[i+1], rmax-prices[i])    // either buy today or keep previous profit
	}

	// Combine the two transactions
	// First transaction ends at i, second starts at i
	res := 0
	for i := 1; i < n; i++ {
		res = max(res, lp[i]+rp[i])
	}

	return res
}