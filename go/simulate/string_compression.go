package simulate

import (
	"strconv"
)

// https://leetcode-cn.com/problems/string-compression/

func compress(chars []byte) int {
	n := len(chars)
	if n == 0 {
		return 0
	}
	ans := 0
	len := 1
	c := chars[0]

	for i := 1; i < n; i++ {
		if chars[i] == c {
			len++
		} else if len == 1 {
			chars[ans] = c
			ans++
			c = chars[i]
		} else {
			chars[ans] = c
			ans++
			c = chars[i]
			int2Byte := make([]byte, 0)
			int2Byte = strconv.AppendInt(int2Byte, int64(len), 10)
			for _, c := range int2Byte {
				chars[ans] = c
				ans++
			}
			len = 1
		}
	}
	chars[ans] = c
	ans++
	if len > 1 {
		int2Byte := make([]byte, 0)
		int2Byte = strconv.AppendInt(int2Byte, int64(len), 10)
		for _, c := range int2Byte {
			chars[ans] = c
			ans++
		}
	}
	return ans
}
