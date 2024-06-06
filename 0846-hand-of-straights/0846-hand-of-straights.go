func isNStraightHand(hand []int, groupSize int) bool {
	if len(hand)%groupSize != 0 {
		return false
	}

	cardCount := make(map[int]int)
	for _, card := range hand {
		cardCount[card]++
	}

	uniqueCards := make([]int, 0, len(cardCount))
	for card := range cardCount {
		uniqueCards = append(uniqueCards, card)
	}

	sort.Ints(uniqueCards)

	for _, card := range uniqueCards {
		if cardCount[card] > 0 {
			count := cardCount[card]
			for i := 0; i < groupSize; i++ {
				if cardCount[card+i] < count {
					return false
				}
				cardCount[card+i] -= count
			}
		}
	}

	return true
}