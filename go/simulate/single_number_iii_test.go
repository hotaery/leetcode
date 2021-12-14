package simulate

import "testing"

func TestSingleNumber(t *testing.T) {
	case1 := singleNumber([]int{1, 2, 1, 3, 2, 5})
	expect1 := []int{3, 5}
	if len(case1) != len(expect1) {
		t.Fatalf("unmatched len, expect=%v, actual=%v\n", expect1, case1)
	}
	for i := 0; i < len(case1); i++ {
		if case1[i] != expect1[i] {
			t.Errorf("expect=%d, actual=%d\n", expect1[i], case1[i])
		}
	}

	case2 := singleNumber([]int{-1, 0})
	expect2 := []int{0, -1} 
	if len(case2) != len(expect2) {
		t.Fatalf("unmatched len, expect=%v, actual=%v\n", expect2, case2)
	}
	for i := 0; i < len(case2); i++ {
		if case2[i] != expect2[i] {
			t.Errorf("expect=%d, actual=%d\n", expect2[i], case2[i])
		}
	}
}
