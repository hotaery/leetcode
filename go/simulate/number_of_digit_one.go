package simulate

import "math"

func countDigitOne(n int) int {
	m := int64(1) 
	n64 := int64(n)
	ans := int64(0)
	for n64 >= m {
		ans += n64/(m*10)*m+int64(math.Min(math.Max(float64(0), float64(n64%(m*10)-m+1)), float64(m)))
		m *= 10
	}
	return int(ans)
}
