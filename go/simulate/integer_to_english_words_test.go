package simulate

import "testing"

func TestNumberToWords(t *testing.T) {
	case1 := 123 
	expect1 := "One Hundred Twenty Three"
	actual1 := numberToWords(case1)
	if actual1 != expect1 {
		t.Errorf("case=%d, expect=%s, actual=%s\n", case1, expect1, actual1)
	}

	case2 := 12345
	expect2 := "Twelve Thousand Three Hundred Forty Five"
	actual2 := numberToWords(case2)
	if actual2 != expect2 {
		t.Errorf("case=%d, expect=%s, actual=%s\n", case2, expect2, actual2)
	}
	
	case3 := 1234567 
	expect3 := "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
	actual3 := numberToWords(case3)
	if actual3 != expect3 {
		t.Errorf("case=%d, expect=%s, actual=%s\n", case3, expect3, actual3)
	}
	
	case4 := 1234567891 
	expect4 := "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
	actual4 := numberToWords(case4)
	if actual4 != expect4 {
		t.Errorf("case=%d, expect=%s, actual=%s\n", case4, expect4, actual4)
	}
}