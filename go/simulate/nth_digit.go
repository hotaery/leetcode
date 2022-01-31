package simulate

import (
	"math"
	"strconv"
)

// binary search
// +---+-----------------------+-------------+---------------+
// | 1 | 1~9                   | 9           | 9             |
// +---+-----------------------+-------------+---------------+
// | 2 | 10~99                 | 90          | 180           |
// +---+-----------------------+-------------+---------------+
// | 3 |100~999                | 900         | 2700          |
// +---+-----------------------+-------------+---------------+
// | x |pow(10,x-1)~pow(10,x)-1|9*pow(10,x-1)|x*9*pow(10,x-1)|
// +---+-----------------------+-------------+---------------+
// find x which n is inside, prevTotalCount < n <= nextTotalCount
// firstly, we need to determine low and high for binary search
// n <= 2^31-1 < 2*10^10
// high=9
// 81*10^9=8.1*10^10>2*10^10

func totalCount(x int) int {
	if x == 0 {
		return 0
	}
	curr, currTotalCount := 1, 9
	for curr < x {
		curr++
		currTotalCount += curr * 9 * int(math.Pow(10, float64(curr-1)))
	}
	return currTotalCount
}

func findNthDigit(n int) int {
	low, high := 1, 9
	for low < high {
		mid := low + (high-low)/2
		count := totalCount(mid)
		if count < n {
			low = mid + 1
		} else {
			high = mid
		}
	}

	x := low
	prevCount := totalCount(x - 1)
	start := int(math.Pow(10, float64(x-1)))
	n -= prevCount
	start += (n - 1) / x
	s := make([]byte, 0)
	s = strconv.AppendInt(s, int64(start), 10)
	n %= x
	if n == 0 {
		n = x
	}
	return int(s[n-1] - '0')
}
