func equationsPossible(equations []string) bool {
    parent := make([]int, 26)
    for i := range parent {
        parent[i] = i
    }
    for _, e := range equations {
        if e[1] == '=' {
            parent[find(parent, int(e[0] - 'a'))] = find(parent, int(e[3] - 'a'))
        }
    }

    for _, e := range equations {
        if e[1] == '!' && find(parent, int(e[0] - 'a')) == find(parent, int(e[3] - 'a')){
            return false
        }
    }
    return true
}

func find(parent []int, x int ) int {
    if parent[x] == x {
        return x
    }
    parent[x] = find(parent, parent[x])
    return parent[x]
}