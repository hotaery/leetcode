package simulate

import "testing"

func TestFractionToDecimal(t *testing.T) {
	case1 := fractionToDecimal(2, 3)
	expect1 := "0.(6)"
	if case1 != expect1 {
		t.Errorf("2/3, expect=%s, actual=%s\n", expect1, case1)
	}
	case2 := fractionToDecimal(2, 1)
	expect2 := "2"
	if case2 != expect2 {
		t.Errorf("2/1, expect=%s, actual=%s\n", expect2, case2)
	}
	case3 := fractionToDecimal(1, 2)
	expect3 := "0.5"
	if case3 != expect3 {
		t.Errorf("1/2, expect=%s, actual=%s\n", expect3, case3)
	}
	case4 := fractionToDecimal(4, 333)
	expect4 := "0.(012)"
	if case4 != expect4 {
		t.Errorf("4/333, expect=%s, actual=%s\n", expect4, case4)
	}
	case5 := fractionToDecimal(1, 5)
	expect5 := "0.2"
	if case5 != expect5 {
		t.Errorf("1/5, expect=%s, actual=%s\n", expect5, case5)
	}

	case6 := fractionToDecimal(1, 6)
	expect6 := "0.1(6)"
	if case6 != expect6 {
		t.Errorf("1/6, expect=%s, actual=%s\n", expect6, case6)
	}
}
