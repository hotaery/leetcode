package simulate

import "testing"

func TestNumberOfArithmeticSlices(t *testing.T) {
	aCase := []int{1, 2, 3, 4}
	actual := numberOfArithmeticSlices(aCase)
	if actual != 3 {
		t.Errorf("numberOfArithmeticSlices(%v), expect=3, actual=%v", aCase, actual)
	}

	aCase = []int{1}
	actual = numberOfArithmeticSlices(aCase)
	if actual != 0 {
		t.Errorf("numberOfArithmeticSlices(%v), expect=0, actual=%v", aCase, actual)
	}

	aCase = []int{1, 2, 3, 5, 7}
	actual = numberOfArithmeticSlices(aCase)
	if actual != 2 {
		t.Errorf("numberOfArithmeticSlices(%v), expect=2, actual=%v", aCase, actual)
	}
}
