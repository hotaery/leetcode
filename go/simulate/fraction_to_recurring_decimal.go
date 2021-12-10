package simulate

import (
	"strconv"
)

func fractionToDecimal(numerator int, denominator int) string {
	numLong := int64(numerator)
	denoLong := int64(denominator)

	ans := make([]byte, 0)
	if numLong % denoLong == 0 {
		return string(strconv.AppendInt(ans, numLong / denoLong, 10))
	}
	if (numLong < 0 && denoLong > 0) || (numLong > 0 && denoLong < 0) {
		ans = append(ans, '-')
	}
	if numLong < 0 {
		numLong = -numLong
	}
	if denoLong < 0 {
		denoLong = -denoLong
	}

	ans = strconv.AppendInt(ans, numLong / denoLong, 10)
	ans = append(ans, '.')
	remaind := numLong % denoLong 
	fraction := make([]byte, 0)	
	m := make(map[int64]int, 0)

	for remaind > 0 {
		_, ok := m[remaind]
		if ok {
			break 
		}
		m[remaind] = len(fraction)
		remaind *= 10
		fraction = strconv.AppendInt(fraction, remaind / denoLong, 10)
		remaind = remaind % denoLong 
	}
	if remaind == 0 {
		ans = append(ans, fraction...)
	}

	if remaind > 0 {
		idx := m[remaind]
		ans = append(ans, fraction[0:idx]...)
		ans = append(ans, '(')
		ans = append(ans, fraction[idx:]...)
		ans = append(ans, ')')	
	}
	return string(ans)
}
