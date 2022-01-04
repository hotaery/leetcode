package simulate

import "testing"

func TestReverseVowels(t *testing.T) {
	case1 := "hello"
	expect1 := "holle"
	actual1 := reverseVowels(case1)
	if actual1 != expect1 {
		t.Errorf("case=%v, expect=%v, actual=%v", case1, expect1, actual1)
	}

	case2 := "leetcode"
	expect2 := "leotcede"
	actual2 := reverseVowels(case2)
	if actual2 != expect2 {
		t.Errorf("case=%v, expect=%v, actual=%v", case2, expect2, actual2)
	}

	case3 := "aA"
	expect3 := "Aa"
	actual3 := reverseVowels(case3)
	if actual2 != expect2 {
		t.Errorf("case=%v, expect=%v, actual=%v", case3, expect3, actual3)
	}
}
