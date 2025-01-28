func setZeroes(matrix [][]int) {
    rows, cols := len(matrix), len(matrix[0])
    firstRowZero := false
    firstColZero := false

    // Check if the first row has any zeros
    for j := 0; j < cols; j++ {
        if matrix[0][j] == 0 {
            firstRowZero = true
            break
        }
    }

    // Check if the first column has any zeros
    for i := 0; i < rows; i++ {
        if matrix[i][0] == 0 {
            firstColZero = true
            break
        }
    }

    // Use the first row and column to mark zero rows and columns
    for i := 1; i < rows; i++ {
        for j := 1; j < cols; j++ {
            if matrix[i][j] == 0 {
                matrix[i][0] = 0
                matrix[0][j] = 0
            }
        }
    }

    // Zero out cells based on the markers in the first row and column
    for i := 1; i < rows; i++ {
        for j := 1; j < cols; j++ {
            if matrix[i][0] == 0 || matrix[0][j] == 0 {
                matrix[i][j] = 0
            }
        }
    }

    // Zero out the first row if needed
    if firstRowZero {
        for j := 0; j < cols; j++ {
            matrix[0][j] = 0
        }
    }

    // Zero out the first column if needed
    if firstColZero {
        for i := 0; i < rows; i++ {
            matrix[i][0] = 0
        }
    }
}
