func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	N1 := len(nums1)
	N2 := len(nums2)
	if N1 < N2 {
		return findMedianSortedArrays(nums2, nums1) // Make sure nums2 is the shorter one.
	}

	lo := 0
	hi := N2 * 2

	for lo <= hi {
		mid2 := (lo + hi) / 2 // Try Cut 2
		mid1 := N1 + N2 - mid2 // Calculate Cut 1 accordingly

		var L1, L2, R1, R2 float64
		if mid1 == 0 {
			L1 = math.Inf(-1) // Use negative infinity if mid1 is 0
		} else {
			L1 = float64(nums1[(mid1-1)/2])
		}

		if mid2 == 0 {
			L2 = math.Inf(-1) // Use negative infinity if mid2 is 0
		} else {
			L2 = float64(nums2[(mid2-1)/2])
		}

		if mid1 == N1*2 {
			R1 = math.Inf(1) // Use positive infinity if mid1 is out of bounds
		} else {
			R1 = float64(nums1[mid1/2])
		}

		if mid2 == N2*2 {
			R2 = math.Inf(1) // Use positive infinity if mid2 is out of bounds
		} else {
			R2 = float64(nums2[mid2/2])
		}

		if L1 > R2 {
			lo = mid2 + 1 // nums1's lower half is too big; need to move C1 left (C2 right)
		} else if L2 > R1 {
			hi = mid2 - 1 // nums2's lower half is too big; need to move C2 left
		} else {
			return (math.Max(L1, L2) + math.Min(R1, R2)) / 2 // Otherwise, that's the right cut
		}
	}
	return -1
}