package simulate

func countBattleships(board [][]byte) int {
	m, n := len(board), len(board[0])
	ans := 0
	check := func(r, c int) bool {
		// up
		if r > 0 && board[r-1][c] == 'X' {
			return false
		}
		// left
		if c > 0 && board[r][c-1] == 'X' {
			return false
		}
		return true
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == '.' {
				continue
			}
			if check(i, j) {
				ans++
			}
		}
	}
	return ans
}
