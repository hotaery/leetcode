package simulate

import "testing"

func TestToHext(t *testing.T) {
	s := toHex(26)
	if s != "1a" {
		t.Errorf("toHex(26), expect=1a, actual=%v", s)
	}

	s = toHex(-1)
	if s != "ffffffff" {
		t.Errorf("toHexr(-1), exoect=ffffffff, actual=%v", s)
	}
}
