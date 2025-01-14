func findThePrefixCommonArray(A []int, B []int) []int {
    n := len(A)
    h1 , h2, res := make([]int, n + 1), make([]int, n + 1), make([]int, n)

    for i := 0 ; i < n ; i++ {
        h1[A[i]]++
        h2[B[i]]++

        temp := 0
        for j := 0 ; j <= n ; j++ {
            temp += min(h1[j] , h2[j])
        }
        res[i] = temp
    }

    return res
}