package simulate

import "testing"

func TestUglyNumber(t *testing.T) {
	if isUgly(6) != true {
		t.Errorf("case=6, expect=true, actual=false\n");
	}

	if isUgly(8) != true {
		t.Errorf("case=8, expect=true, actual=false\n");
	}

	if isUgly(14) == true {
		t.Errorf("case=14, expect=false, actual=true\n");
	}

	if isUgly(1) != true {
		t.Errorf("case=1, expect=true, actual=false\n");
	}
}