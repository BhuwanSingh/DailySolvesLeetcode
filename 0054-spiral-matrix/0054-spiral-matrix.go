func spiralOrder(matrix [][]int) []int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return []int{}
    }
    n := len(matrix) * len(matrix[0])
    result := make([]int, n)
    top, bottom, left, right := 0, len(matrix)-1, 0, len(matrix[0])-1

    i := 0
    for {
        // Traverse from left to right
        for j := left; j <= right; j++ {
            result[i] = matrix[top][j]
            i++
        }
        top++
        if top > bottom {
            break
        }

        // Traverse from top to bottom
        for j := top; j <= bottom; j++ {
            result[i] = matrix[j][right]
            i++
        }
        right--
        if left > right {
            break
        }

        // Traverse from right to left
        for j := right; j >= left; j-- {
            result[i] = matrix[bottom][j]
            i++
        }
        bottom--
        if top > bottom {
            break
        }

        // Traverse from bottom to top
        for j := bottom; j >= top; j-- {
            result[i] = matrix[j][left]
            i++
        }
        left++
        if left > right {
            break
        }
    }
    return result
}
