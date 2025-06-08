func combinationSum(candidates []int, target int) [][]int {
    sort.Ints(candidates) // Sort candidates to enable pruning

    var res [][]int
    var path []int

    var dfs func(start int, target int)
    dfs = func(start int, target int) {
        if target == 0 {
            // Found valid combination
            combination := make([]int, len(path))
            copy(combination, path)
            res = append(res, combination)
            return
        }

        for i := start; i < len(candidates); i++ {
            candidate := candidates[i]
            
            // Prune: if candidate > target → no point in continuing
            if candidate > target {
                break
            }

            path = append(path, candidate)
            dfs(i, target - candidate) // Reuse the same element
            path = path[:len(path)-1]   // Backtrack
        }
    }

    dfs(0, target)
    return res
}
