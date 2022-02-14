package simulate

import "testing"

func TestFrequencySort(t *testing.T) {
	aCase := "tree"
	expect := "eert"
	actual := frequencySort(aCase)
	if actual != expect {
		t.Errorf("frequencySort(%v), expect=%v, actual=%v", aCase, expect, actual)
	}

	aCase = "cccaaa"
	expect = "aaaccc"
	actual = frequencySort(aCase)
	if actual != expect {
		t.Errorf("frequencySort(%v), expect=%v, actual=%v", aCase, expect, actual)
	}
	
	aCase = "Aabb"
	expect = "bbAa"
	actual = frequencySort(aCase)
	if actual != expect {
		t.Errorf("frequencySort(%v), expect=%v, actual=%v", aCase, expect, actual)
	}
}
