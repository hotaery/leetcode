package simulate

import "leetcode/common"

func deleteNode(node *common.ListNode) {
	/*
		prev := node
		for node.Next != nil {
			node.Val = node.Next.Val
			prev = node
			node = node.Next
		}
		prev.Next = nil
	*/
	node.Val = node.Next.Val 
	node.Next = node.Next.Next
}
