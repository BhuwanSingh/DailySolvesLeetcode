func gameOfLife(board [][]int)  {
    for i := range board {
        for j := range board[0] {
            count := 0

            for m := max(0 , i - 1); m <= min(i + 1, len(board) - 1) ; m++ {
                for n := max(0 , j - 1); n <= min(j + 1, len(board[0]) - 1) ; n++ {
                    if m == i && n == j {
                        continue
                    }
                    count += board[m][n] & 1
                }
            }
            if count | board[i][j] == 3 {
                board[i][j] |= 2
            }
        }
    }
    for i := range board {
        for j := range board[0] {
            board[i][j] >>= 1
        }
    }
}