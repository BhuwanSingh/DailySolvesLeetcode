type MinHeap []int

func (m MinHeap) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m MinHeap) Len() int {
	return len(m)
}

func (m MinHeap) Less(i, j int) bool {
	return m[i] < m[j]
}

func (m *MinHeap) Push(x interface{}) {
	*m = append(*m, x.(int))
}

func (m *MinHeap) Pop() interface{} {
	old := *m
	n := len(old)
	*m = old[: n - 1]
	return old[n - 1]
}

func maxEvents(events [][]int) int {
	sort.Slice(events, func(i, j int) bool {
		return events[i][0] < events[j][0]
	})

	m := MinHeap{}
	day := 1
	event := 0
	attended := 0

	for event < len(events) || len(m) > 0 {
        for len(m) > 0 && m[0] < day {
			heap.Pop(&m)
		}

		if event < len(events) && len(m) == 0 {
			day = int(math.Max(float64(day), float64(events[event][0])))
		}

		for event < len(events) && events[event][0] == day {
			heap.Push(&m, events[event][1])
			event++
		}

		if len(m) > 0 {
			attended++
			heap.Pop(&m)
		}
		day++
	}

	return attended
}