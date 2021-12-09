package simulate

// https://leetcode-cn.com/problems/set-matrix-zeroes/

func setZeroes(matrix [][]int) {
	rowFlag, colFlag := false, false 
	m := len(matrix)
	n := len(matrix[0]) 

	for i := 0; i < n; i++ {
		if matrix[0][i] == 0 {
			rowFlag = true 
		}
	}
	for i := 0; i < m; i++ {
		if matrix[i][0] == 0 {
			colFlag = true 
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][j] == 0 {
				matrix[0][j] = 0
				matrix[i][0] = 0 
			}
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[0][j] == 0 || matrix[i][0] == 0 {
				matrix[i][j] = 0
			}
		}
	}

	if rowFlag {
		for i := 0; i < n; i++ {
			matrix[0][i] = 0
		}
	}

	if colFlag {
		for i := 0; i < m; i++ {
			matrix[i][0] = 0
		}
	}
}
