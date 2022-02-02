package simulate

import (
	"sort"
)

// https://leetcode-cn.com/problems/third-maximum-number/

type IntArr []int

func (arr IntArr) Len() int           { return len(arr) }
func (arr IntArr) Less(i, j int) bool { return arr[i] > arr[j] }
func (arr IntArr) Swap(i, j int)      { arr[i], arr[j] = arr[j], arr[i] }

func thirdMax(nums []int) int {
	sort.Sort(IntArr(nums))
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
