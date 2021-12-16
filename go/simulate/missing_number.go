package simulate

// https://leetcode-cn.com/problems/missing-number/

func missingNumber(nums []int) int {
	n := len(nums)
	total := (0 + n) * (n + 1) / 2
	sum := 0
	for _, v := range nums {
		sum += v
	}
	return total - sum
}
