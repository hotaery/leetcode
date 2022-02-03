package simulate

import "math"

// https://leetcode-cn.com/problems/maximum-product-of-word-lengths/

func maxProduct(words []string) int {
	mask := make(map[int]int)

	for _, word := range words {
		m := 0
		for _, a := range word {
			m |= (1 << (a - 'a'))
		}
		c, ok := mask[m]
		if ok {
			mask[m] = int(math.Max(float64(c), float64(len(word))))
		} else {
			mask[m] = len(word)
		}
	}
	ans := 0
	for k, v := range mask {
		for kk, vv := range mask {
			if k&kk == 0 {
				ans = int(math.Max(float64(ans), float64(v*vv)))
			}
		}
	}
	return ans
}
