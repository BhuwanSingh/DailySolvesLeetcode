func minOperations(a []int, k int) int {
	sort.Ints(a)
	var b []int

	for i, j, count, x, y := 0, 0, 0, 0, 0; ; count++ {
		if i < len(a) && (j >= len(b) || a[i] <= b[j]) {
			x = a[i]
			i++
		} else {
			x = b[j]
			j++
		}
		if !(k > x) {
			return count
		}
		if i < len(a) && (j >= len(b) || a[i] <= b[j]) {
			y = a[i]
			i++
		} else {
			y = b[j]
			j++
		}
		t := int64(2 * x + y) // test overflow
		if t < int64(k) {
			b = append(b, int(t))
		} else {
			b = append(b, k)
		}
	}
	return -1
}