package simulate

import (
	"leetcode/common"
	"testing"
)

func TestDeleteNode(t *testing.T) {
	head, node := common.ConstructLinkListAndReturnIth([]int{4, 5, 1, 9}, 2)
	deleteNode(node)
	expect1 := []int{4, 1, 9}
	i := 0
	for head != nil {
		if i == len(expect1) {
			t.Errorf("%d, expect=nil, actual=%d\n", i, head.Val)
		} else {
			if head.Val != expect1[i] {
				t.Errorf("%d, expect=%d, actual=%d\n", i, expect1[i], head.Val)
			}
		}
		i++
		head = head.Next
	}

	head, node = common.ConstructLinkListAndReturnIth([]int{-3, 5, -99}, 1)
	deleteNode(node)
	expect2 := []int{5, -99}
	i = 0
	for head != nil {
		if i == len(expect2) {
			t.Errorf("%d, expect=nil, actual=%d\n", i, head.Val)
		} else {
			if head.Val != expect2[i] {
				t.Errorf("%d, expect=%d, actual=%d\n", i, expect2[i], head.Val)
			}
		}
		i++
		head = head.Next
	}
}
