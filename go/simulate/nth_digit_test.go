package simulate

import "testing"

func TestFindNthDigit(t *testing.T) {
	n := findNthDigit(3)
	if n != 3 {
		t.Errorf("findNthDigit(3), expect=3, actual=%v", n)
	}

	n = findNthDigit(11)
	if n != 0 {
		t.Errorf("findNthDigit(11), expect=0, actual=%v", n)
	}
}
