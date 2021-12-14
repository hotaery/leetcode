package common_test

import (
	"leetcode/common"
	"testing"
)

func TestSingleLinkList(t *testing.T) {
	arr := []int{1, 3, 5, 7, 9}
	head := common.ConstructLinkList(arr)
	i := 0
	for head != nil {
		if head.Val != arr[i] {
			t.Errorf("list[%d], expect=%d, actual=%d\n", i, arr[i], head.Val)
		}
		head = head.Next
		i++
	}

	head, node := common.ConstructLinkListAndReturnIth(arr, 3)
	if node.Val != arr[2] {
		t.Errorf("list[2], expect=%d, actual=%d\n", arr[2], node.Val)
	}
	i = 0
	for head != nil {
		if head.Val != arr[i] {
			t.Errorf("list[%d], expect=%d, actual=%d\n", i, arr[i], head.Val)
		}
		head = head.Next
		i++
	}
}
