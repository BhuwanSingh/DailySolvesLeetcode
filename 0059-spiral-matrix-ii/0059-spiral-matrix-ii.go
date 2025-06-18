func generateMatrix(n int) [][]int {
    sqn := n * n
    mir, mxr := 0 , n - 1
    mic, mxc := 0 , n - 1
    res := make([][]int, n)
    for i := range res {
        res[i] = make([]int, n)
    }
    i := 1
    for i <= sqn {
        for j := mic ; j <= mxc ; j++ {
            res[mir][j] = i
            i++
        }
        mir++
        for j := mir ; j <= mxr ; j++ {
            res[j][mxc] = i
            i++
        }
        mxc--
        for j := mxc ; j >= mic ; j-- {
            res[mxr][j] = i
            i++
        }
        mxr--
        for j := mxr ; j >= mir ; j-- {
            res[j][mic] = i
            i++
        }
        mic++
    }
    return res
}