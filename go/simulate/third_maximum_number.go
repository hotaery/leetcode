package simulate

import (
	"sort"
	"leetcode/common"
)

// https://leetcode-cn.com/problems/third-maximum-number/

func thirdMax(nums []int) int {
	sort.Sort(common.IntArr(nums))
	no := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			continue
		}
		no++
		if no == 3 {
			return nums[i]
		}
	}

	return nums[0]
}
