package simulate

import "testing"

func TestThirdMax(t *testing.T) {
	aCase := []int{1, 2, 3}
	expect := 1
	actual := thirdMax(aCase)
	if expect != actual {
		t.Errorf("thirdMax(%v), expect=%v, actual=%v", aCase, expect, actual)
	}

	aCase = []int{1, 2}
	expect = 2
	actual = thirdMax(aCase)
	if expect != actual {
		t.Errorf("thirdMax(%v), expect=%v, actual=%v", aCase, expect, actual)
	}

	aCase = []int{2, 2, 3, 1}
	expect = 1
	actual = thirdMax(aCase)
	if expect != actual {
		t.Errorf("thirdMax(%v), expect=%v, actual=%v", aCase, expect, actual)
	}
}
