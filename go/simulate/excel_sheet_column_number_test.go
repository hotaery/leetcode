package simulate

import "testing"

func TestTitleToNumber(t *testing.T) {
	case1 := titleToNumber("A")
	expect1 := 1 
	if case1 != expect1 {
		t.Errorf("A, expect=%d, actual=%d\n", expect1, case1) 
	}

	case2 := titleToNumber("AB")
	expect2 := 28 
	if case2 != expect2 {
		t.Errorf("AB, expect=%d, actual=%d\n", expect2, case2) 
	}

	case3 := titleToNumber("ZY")
	expect3 := 701 
	if case3 != expect3 {
		t.Errorf("ZY, expect=%d, actual=%d\n", expect3, case3)
	}

	case4 := titleToNumber("FXSHRXW")
	expect4 := 2147483647
	if case4 != expect4 {
		t.Errorf("FXSHRXW, expect=%d, actual=%d\n", expect4, case4)
	}
}