func candy(ratings []int) int {
    n := len(ratings)
    arr := slices.Repeat([]int{1}, n)
    for i := 1 ; i < n ; i++ {
        if ratings[i] > ratings[i - 1] {
            arr[i] = arr[i - 1] + 1
        }
    }

    for i := n - 2 ; i >= 0 ; i-- {
        if ratings[i] > ratings[i + 1] && arr[i] <= arr[i + 1] {
            arr[i] = arr[i + 1] + 1
        }
    }

    res := 0
    for _ , val := range(arr) {
        res += val
        // fmt.Print(val, " ")
    }
    // fmt.Println()
    return res
}