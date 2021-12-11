package simulate

// https://leetcode-cn.com/problems/excel-sheet-column-title/

func convertToTitle(columnNumber int) string {
	ans := make([]byte, 0)
	for {
		columnNumber--
		remain := columnNumber % 26
		ans = append(ans, 'A'+byte(remain))
		columnNumber = columnNumber / 26
		if columnNumber == 0 {
			break
		}
	}

	n := len(ans)
	for i := 0; i < n/2; i++ {
		ans[i], ans[n-i-1] = ans[n-1-i], ans[i]
	}
	return string(ans)
}
