package doublepointer

import "math"

func lengthOfLongestSubstring(s string) int {
	n := len(s)
	if n < 2 {
		return n
	}
	arr := make([]int, 256)

	left, right := 0, 1
	ans := 1
	arr[uint(s[left])] = 1

	for ; right < len(s); right++ {
		idx := uint(s[right])
		if arr[idx] == 0 {
			arr[idx] = 1
			continue
		}
		ans = int(math.Max(float64(ans), float64(right-left)))
		for s[left] != s[right] {
			arr[uint(s[left])] = 0
			left++
		}
		if left != right {
			left++ 
		}
		arr[idx] = 1 
	}
	ans = int(math.Max(float64(ans), float64(right-left)))
	return ans
}
