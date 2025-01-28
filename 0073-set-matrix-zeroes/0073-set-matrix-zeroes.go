func setZeroes(matrix [][]int) {
    rows, cols := len(matrix), len(matrix[0])
    rowZero := make([]bool, rows)
    colZero := make([]bool, cols)

    // First pass: identify the rows and columns that need to be zeroed
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if matrix[i][j] == 0 {
                rowZero[i] = true
                colZero[j] = true
            }
        }
    }

    // Second pass: set the identified rows and columns to zero
    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if rowZero[i] || colZero[j] {
                matrix[i][j] = 0
            }
        }
    }
}
