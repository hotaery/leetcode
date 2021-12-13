package simulate

import "testing"

func TestCountDigitOne(t *testing.T) {
	case1 := countDigitOne(13)
	expect1 := 6
	if case1 != expect1 {
		t.Errorf("countDigitOne(13), expect=%d, actual=%d\n", expect1, case1)
	}

	case2 := countDigitOne(0)
	expect2 := 0
	if case2 != expect2 {
		t.Errorf("countDigitOne(0), expect=%d, actual=%d\n", expect2, case2)
	}
}