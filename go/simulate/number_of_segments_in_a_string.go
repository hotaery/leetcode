package simulate

// https://leetcode-cn.com/problems/number-of-segments-in-a-string/submissions/

func countSegments(s string) int {
	n := len(s)
	ans := 0

	for i := 0; i < n; {
		if s[i] == ' ' {
			i++
			continue
		}

		ans++
		for i < n && s[i] != ' ' {
			i++
		}
	}

	return ans
}
