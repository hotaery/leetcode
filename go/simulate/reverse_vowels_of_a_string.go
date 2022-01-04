package simulate

import (
	"sort"
)

// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/

var vowels []byte = []byte{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}

func reverseVowels(s string) string {
	idx := make([]int, 0)
	n := len(vowels)

	for j, x := range []byte(s) {
		i := sort.Search(n, func(k int) bool { 
			return vowels[k] >= x
		})
		if i < n && vowels[i] == x {
			idx = append(idx, j)
		}
	}

	if len(idx) < 2 {
		return s
	}

	left, right := 0, len(idx)-1
	ans := []byte(s)

	for left < right {
		ans[idx[left]], ans[idx[right]] = ans[idx[right]], ans[idx[left]]
		left++
		right--
	}
	return string(ans)
}
