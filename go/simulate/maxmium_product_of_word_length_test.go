package simulate

import "testing"

func TestMaxProduct(t *testing.T) {
	case1 := []string{"abcw","baz","foo","bar","xtfn","abcdef"} 
	expect1 := 16 
	actual1 := maxProduct(case1)
	if actual1 != expect1 {
		t.Errorf("case=%v, expect=%v, actual=%v", case1, expect1, actual1)
	}

	case2 := []string{"a","ab","abc","d","cd","bcd","abcd"}
	expect2 := 4
	actual2 := maxProduct(case2)
	if actual2 != expect2 {
		t.Errorf("case=%v, expect=%v, actual=%v", case2, expect2, actual2)
	}

	case3 := []string{"a","aa","aaa","aaaa"}
	expect3 := 0
	actual3 := maxProduct(case3)
	if actual3 != expect3 {
		t.Errorf("case=%v, expect=%v, actual=%v", case3, expect3, actual3)
	}
}