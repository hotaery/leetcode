package simulate

import "testing"

func TestGetHint(t *testing.T) {
	actual1 := getHint("1807", "7810")
	expect1 := "1A3B"
	if actual1 != expect1 {
		t.Errorf("getHint(1807, 7810), expect=%s, actual=%s\n", expect1, actual1)
	}

	actual2 := getHint("1123", "0111")
	expect2 := "1A1B"
	if actual2 != expect2 {
		t.Errorf("getHint(1123, 0111), expect=%s, actual=%s\n", expect2, actual2)
	}

	actual3 := getHint("1", "0")
	expect3 := "0A0B"
	if actual3 != expect3 {
		t.Errorf("getHint(1, 0), expect=%s, actual=%s\n", expect3, actual3)
	}
	
	actual4 := getHint("1", "1")
	expect4 := "1A0B"
	if actual4 != expect4 {
		t.Errorf("getHint(1, 1), expect=%s, actual=%s\n", expect4, actual4)
	}
}