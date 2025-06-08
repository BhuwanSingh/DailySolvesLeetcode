func lexicalOrder(n int) []int {
    strs := []string{}
    for i := 1 ; i <= n ; i++ {
        strs = append(strs , strconv.Itoa(i))
    }
    sort.Strings(strs)
    res := []int{}
    for i := 0; i < n; i++ {
        num, _ := strconv.Atoi(strs[i])
        res = append(res, num)
    }
    return res
}