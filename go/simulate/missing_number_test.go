package simulate

import "testing"

func TestMissingNumber(t *testing.T) {
	case1 := []int{3, 0, 1}
	expect1 := 2
	actual1 := missingNumber(case1)
	if actual1 != expect1 {
		t.Errorf("missing(%v), expect=%d, actual=%d\n", case1, expect1, actual1)
	}

	case2 := []int{1, 0}
	expect2 := 2
	actual2 := missingNumber(case2)
	if actual2 != expect2 {
		t.Errorf("missing(%v), expect=%d, actual=%d\n", case2, expect2, actual2)
	}

	case3 := []int{9, 6, 4, 2, 3, 5, 7, 0, 1}
	expect3 := 8
	actual3 := missingNumber(case3)
	if actual3 != expect3 {
		t.Errorf("missing(%v), expect=%d, actual=%d\n", case3, expect3, actual3)
	}

	case4 := []int{0}
	expect4 := 1
	actual4 := missingNumber(case4)
	if actual4 != expect4 {
		t.Errorf("missing(%v), expect=%d, actual=%d\n", case4, expect4, actual4)
	}
}
