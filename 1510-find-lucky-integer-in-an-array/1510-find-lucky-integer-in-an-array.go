func findLucky(arr []int) int {
    cnt := map[int]int{}
    for _, val := range arr {
        cnt[val]++
    }
    res := []int{}
    for key, val := range cnt {
        // fmt.Println(key , " ", val)
        if key == val {
            res = append(res, val)
        }
    }
    if len(res) == 0 {
        return -1
    }
    sort.Ints(res)
    return res[len(res) - 1]
}