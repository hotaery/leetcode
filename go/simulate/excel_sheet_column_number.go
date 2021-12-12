package simulate

// https://leetcode-cn.com/problems/excel-sheet-column-number/

func titleToNumber(columnTitle string) int {
	base := 1
	ans := 0
	for i := len(columnTitle) - 1; i >= 0; i-- {
		ans += (int(columnTitle[i]-'A') + 1) * base
		base *= 26
	}
	return ans
}
