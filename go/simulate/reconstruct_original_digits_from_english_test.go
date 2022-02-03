package simulate

import "testing"

func TestOriginalDigits(t *testing.T) {
	aCase := "owoztneoer"
	expect := "012"
	actual := originalDigits(aCase)
	if expect != actual {
		t.Errorf("originalDigits(%v), expect=%v, actual=%v", aCase, expect, actual)
	}

	aCase = "fviefuro"
	expect = "45"
	actual = originalDigits(aCase)
	if expect != actual {
		t.Errorf("originalDigits(%v), expect=%v, actual=%v", aCase, expect, actual)
	}

	aCase = "nein"
	expect = "9"
	actual = originalDigits(aCase)
	if expect != actual {
		t.Errorf("originalDigits(%v), expect=%v, actual=%v", aCase, expect, actual)
	}
}
