package doublepointer

import "testing"

func TestLengthOfLongestSubstring(t *testing.T) {
	n1 := lengthOfLongestSubstring("abcabcbb")
	if n1 != 3 {
		t.Errorf("lengthOfLongestSubstring(abcabcbb), expect=3, actual=%v", n1)
	}

	n2 := lengthOfLongestSubstring("bbbbb")
	if n2 != 1 {
		t.Errorf("lengthOfLongestSubstring(bbbbb), expect=1, actual=%v", n2)
	}

	n3 := lengthOfLongestSubstring("pwwkew")
	if n3 != 3 {
		t.Errorf("lengthOfLongestSubstring(pwwkew), expect=3, actual=%v", n3)
	}
}
