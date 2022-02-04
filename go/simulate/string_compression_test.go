package simulate

import "testing"

func TestCompress(t *testing.T) {
	check := func(lhs []byte, rhs []byte) bool {
		if len(lhs) != len(rhs) {
			return false
		}

		for i := 0; i < len(lhs); i++ {
			if lhs[i] != rhs[i] {
				return false
			}
		}
		return true
	}
	aCase := []byte{'a', 'a', 'b', 'b', 'c', 'c', 'c'}
	expect := []byte{'a', '2', 'b', '2', 'c', '3'}
	actual := compress(aCase)
	if actual != len(expect) || !check(aCase[0:actual], expect) {
		t.Errorf("expect=%q, actual=%q", expect, aCase[0:actual])
	}

	aCase = []byte{'a'}
	expect = []byte{'a'}
	actual = compress(aCase)
	if actual != len(expect) || !check(aCase[0:actual], expect) {
		t.Errorf("expect=%q, actual=%q", expect, aCase[0:actual])
	}

	aCase = []byte{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}
	expect = []byte{'a', 'b', '1', '2'}
	actual = compress(aCase)
	if actual != len(expect) || !check(aCase[0:actual], expect) {
		t.Errorf("expect=%q, actual=%q", expect, aCase[0:actual])
	}
}
