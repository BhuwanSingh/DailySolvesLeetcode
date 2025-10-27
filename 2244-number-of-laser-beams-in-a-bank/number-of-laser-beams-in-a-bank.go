func numberOfBeams(bank []string) int {
	totalBeams := 0
	prevRowDeviceCount := 0

	for _, row := range bank {
		currentRowDeviceCount := strings.Count(row, "1")

		if currentRowDeviceCount > 0 {

			totalBeams += prevRowDeviceCount * currentRowDeviceCount

			prevRowDeviceCount = currentRowDeviceCount
		}
	}

	return totalBeams
}