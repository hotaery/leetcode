package simulate

import "testing"

func TestReverseBits(t *testing.T) {
	case1 := reverseBits(43261596)
	expect1 := uint32(964176192)
	if case1 != expect1 {
		t.Errorf("reverseBits(%b), expect=%b, actual=%b\n", 43261596, expect1, case1)
	}

	case2 := reverseBits(4294967293)
	expect2 := uint32(3221225471)
	if case2 != expect2 {
		t.Errorf("reverseBits(%b), expect=%b, actual=%b\n", 4294967293, expect2, case2)
	}
}
