package simulate 

// https://leetcode-cn.com/problems/integer-to-english-words/

var digits map[int]string = map[int]string{
	0: "Zero", 
	1: "One", 
	2: "Two", 
	3: "Three", 
	4: "Four", 
	5: "Five", 
	6: "Six",
	7: "Seven", 
	8: "Eight", 
	9: "Nine",
}

var tens map[int]string = map[int]string {
	10: "Ten", 
	11: "Eleven",
	12: "Twelve", 
	13: "Thirteen", 
	14: "Fourteen", 
	15: "Fifteen", 
	16: "Sixteen", 
	17: "Seventeen", 
	18: "Eighteen", 
	19: "Nineteen",
}

var multiTen map[int]string = map[int]string {
	20: "Twenty",
	30: "Thirty",
	40: "Forty", 
	50: "Fifty", 
	60: "Sixty",
	70: "Seventy", 
	80: "Eighty", 
	90: "Ninety",
}

var other map[int]string = map[int]string {
	100: "Hundred", 
	1000: "Thousand", 
	1000000: "Million", 
	1000000000: "Billion",
}

var otherArr []int = []int{1000000000, 1000000, 1000, 100}

func helper(num int) []byte {
	ans := make([]byte, 0)
	for _, v := range otherArr {
		if num / v == 0 {
			continue 
		}
		ans = append(ans, helper(num / v)...)
		ans = append(ans, ' ')
		ans = append(ans, []byte(other[v])...) 
		if num % v != 0 {
			ans = append(ans, ' ')
			ans = append(ans, helper(num % v)...)
		}
		return ans 
	}

	// num < 100 
	t := num / 10 
	if t > 1 {
		ans = append(ans, []byte(multiTen[t*10])...)
		if num % 10 > 0 {
			ans = append(ans, ' ')
			ans = append(ans, []byte(digits[num % 10])...)
		}
		return ans 
	}

	if t > 0 {
		return []byte(tens[num])
	}

	return []byte(digits[num])
}

func numberToWords(num int) string {
	return string(helper(num))
}