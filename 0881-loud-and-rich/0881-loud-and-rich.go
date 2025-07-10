func loudAndRich(richer [][]int, quiet []int) []int {
    n := len(quiet)
    mapOfQuiet := map[int]int{}
    for i := range quiet {
        mapOfQuiet[quiet[i]] = i
    }
    // for i, val := range mapOfQuiet {
    //     fmt.Println(i , " ", val)
    // }

    answer := make([]int, n)
    for i := range answer {
        answer[i] = -1
    }

    adj := make([][]int , n)
    for i := range richer {
        adj[richer[i][1]] = append(adj[richer[i][1]] , richer[i][0])
    }
    var dfs func( person int ) int 
    dfs = func( person int ) int {
        if answer[person] != -1 {
            return answer[person]
        }

        res := quiet[person]        
        for i := range adj[person] {
            res = min(res , dfs(adj[person][i]))
        }
        answer[person] = res
        return res
    }

    for i := 0; i < n ; i++ {
        dfs(i)
    }
    for i := range answer {
        // fmt.Print(mapOfQuiet[answer[i]] , " ", answer[i])
        answer[i] = mapOfQuiet[answer[i]]
        // fmt.Println()
    }

    return answer
    
}