package simulate

// https://leetcode-cn.com/problems/arithmetic-slices/

func lastSliceIndex(nums []int, start int) int {
	n := len(nums)
	if n-start < 3 {
		return -1
	}

	diff := nums[start+1] - nums[start]
	last := n - 1
	for i := start + 2; i < n; i++ {
		if nums[i]-nums[i-1] != diff {
			last = i - 1
			break
		}
	}

	if last-start+1 < 3 {
		return -1
	}
	return last
}

func numberOfArithmeticSlices(nums []int) int {
	n := len(nums)
	if n < 3 {
		return 0
	}

	ans := 0
	for start := 0; start < n; {
		last := lastSliceIndex(nums, start)
		if last == -1 {
			start++
		} else {
			l := last - start + 1
			ans += (l - 2) * (l - 1) / 2
			start = last
		}
	}
	return ans
}
