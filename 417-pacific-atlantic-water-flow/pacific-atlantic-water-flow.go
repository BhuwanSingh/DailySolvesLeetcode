func pacificAtlantic(heights [][]int) [][]int {
	if len(heights) == 0 {
		return [][]int{}
	}

	n, m := len(heights), len(heights[0])
	visited := make([][]int, n)
	for i := range visited {
		visited[i] = make([]int, m)
	}

	res := make([][]int, 0)

	var dfs func(x, y, prev, visval int)
	dfs = func(x, y, prev, visval int) {
		if x < 0 || x >= n || y < 0 || y >= m {
			return
		}
		if heights[x][y] < prev {
			return
		}
		if visited[x][y]&visval == visval {
			return
		}

		visited[x][y] |= visval
		if visited[x][y] == 3 {
			res = append(res, []int{x, y})
		}

		cur := heights[x][y]
		dfs(x-1, y, cur, visited[x][y])
		dfs(x, y-1, cur, visited[x][y])
		dfs(x+1, y, cur, visited[x][y])
		dfs(x, y+1, cur, visited[x][y])
	}

	for i := 0; i < n; i++ {
		dfs(i, 0, math.MinInt, 1)     // Pacific
		dfs(i, m-1, math.MinInt, 2)   // Atlantic
	}

	for j := 0; j < m; j++ {
		dfs(0, j, math.MinInt, 1)     // Pacific
		dfs(n-1, j, math.MinInt, 2)   // Atlantic
	}

	return res
}
