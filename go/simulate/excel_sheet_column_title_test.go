package simulate

import "testing"

func TestConvertToTitle(t *testing.T) {
	case1 := convertToTitle(1)
	expect1 := "A"
	if case1 != expect1 {
		t.Errorf("input 1, expect=%s, actual=%s\n", expect1, case1) 
	}

	case2 := convertToTitle(701)
	expect2 := "ZY"
	if case2 != expect2 {
		t.Errorf("input 701, expect=%s, actual=%s\n", expect2, case2) 
	}

	case3 := convertToTitle(28)
	expect3 := "AB"
	if case3 != expect3 {
		t.Errorf("input 28, expect=%s, actual=%s\n", expect3, case3) 
	}

	case4 := convertToTitle(2147483647) 
	expect4 := "FXSHRXW"
	if case4 != expect4 {
		t.Errorf("input 2147483647, expect=%s, actual=%s\n", expect4, case4)
	}
}
