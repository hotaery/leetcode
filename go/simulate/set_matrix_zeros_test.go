package simulate

import "testing"

func TestSetMatrixZeros(t *testing.T) {
	case1 := [][]int{
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
	}

	expect1 := [][]int{
		{1, 0, 1},
		{0, 0, 0},
		{1, 0, 1},
	}

	setZeroes(case1)
	for i := 0; i < len(case1); i++ {
		for j := 0; j < len(case1[0]); j++ {
			if case1[i][j] != expect1[i][j] {
				t.Errorf("i=%d,j=%d,actual=%d,expect=%d\n", i, j, case1[i][j], expect1[i][j])
			}
		}
	}

	case2 := [][]int{
		{0, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 1, 5},
	}

	expect2 := [][]int{
		{0, 0, 0, 0},
		{0, 4, 5, 0},
		{0, 3, 1, 0},
	}
	setZeroes(case2)
	for i := 0; i < len(case2); i++ {
		for j := 0; j < len(case2[0]); j++ {
			if case2[i][j] != expect2[i][j] {
				t.Errorf("i=%d,j=%d,actual=%d,expect=%d\n", i, j, case2[i][j], expect2[i][j])
			}
		}
	}
}
