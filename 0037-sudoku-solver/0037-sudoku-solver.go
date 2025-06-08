func solveSudoku(board [][]byte)  {
    solve(board)
}

func solve(board [][]byte) bool {
    for row := 0; row < 9; row++ {
        for col := 0; col < 9; col++ {
            if board[row][col] == '.' {
                for num := byte('1'); num <= '9'; num++ {
                    if isValid(board, row, col, num) {
                        board[row][col] = num
                        if solve(board) {
                            return true
                        }
                        board[row][col] = '.'
                    }
                }
                return false
            }
        }
    }
    return true
}

func isValid(board [][]byte, row, col int, num byte) bool {
    for i := 0; i < 9; i++ {
        if board[row][i] == num || board[i][col] == num {
            return false
        }
    }
    startRow, startCol := (row/3)*3, (col/3)*3
    for i := startRow; i < startRow + 3 ; i++ {
        for j := startCol; j < startCol + 3; j++ {
            if board[i][j] == num {
                return false
            }
        }
    }
    return true
}