package simulate

import (
	"math"
	"strconv"
)

// https://leetcode-cn.com/problems/nth-digit/

func findNthDigit(n int) int {
	digit := 1
	count := 9
	total := digit * count

	for n > total {
		n -= total
		count = int(9 * math.Pow(10, float64(digit)))
		digit++
		total = digit * count
	}

	no := n / digit
	re := n % digit
	if re != 0 {
		no++
	} else {
		re = digit
	}

	start := int64(math.Pow(10, float64(digit-1)))
	start += int64(no - 1)
	s := make([]byte, 0)
	s = strconv.AppendInt(s, start, 10)
	return int(s[re-1] - '0')
}
