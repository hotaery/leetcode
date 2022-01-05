package simulate

import "testing"

func TestCanConstruct(t *testing.T) {
	if canConstruct("a", "b") {
		t.Errorf("canConstruct(a, b), expect=false, actual=true")
	}

	if canConstruct("aa", "ab") {
		t.Errorf("canConstruct(aa, ab), expect=false, actual=true")
	}

	if !canConstruct("aa", "aab") {
		t.Errorf("canConstruct(aa, aab), expect=true, actual=false")
	}
}
