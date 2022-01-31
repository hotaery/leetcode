package simulate

// https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/

// -2^31 <= num <= 2^31 - 1
// 80000000 <= num <= 7fffffff

var hexStr string = "0123456789abcdef"

func toHexHelper(num uint32) string {
	if num == 0 {
		return "0"
	}
	res := make([]byte, 0)
	for num > 0 {
		i := num % 16
		num /= 16
		res = append(res, hexStr[i])
	}

	left, right := 0, len(res)-1
	for left < right {
		res[left], res[right] = res[right], res[left]
		left++
		right--
	}
	return string(res)
}

func toHex(num int) string {
	return toHexHelper(uint32(num))
}
