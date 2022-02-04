package simulate

import "testing"

func TestCountSegments(t *testing.T) {
	aCase := "Hello, my name is John"
	expect := 5
	actual := countSegments(aCase)
	if expect != actual {
		t.Errorf("countSegments(%s), expect=%d, actual=%d", aCase, expect, actual)
	}

	aCase = "hello"
	expect = 1
	actual = countSegments(aCase)
	if expect != actual {
		t.Errorf("countSegments(%s), expect=%d, actual=%d", aCase, expect, actual)
	}
}
