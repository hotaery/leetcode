package common

type ListNode struct {
	Val  int
	Next *ListNode
}

func ConstructLinkList(arr []int) *ListNode {
	head := &ListNode{
		Val:  0,
		Next: nil,
	}
	curr := head
	for _, v := range arr {
		node := new(ListNode)
		node.Val = v
		node.Next = nil
		curr.Next = node
		curr = curr.Next
	}
	return head.Next
}

func ConstructLinkListAndReturnIth(arr []int, i int) (*ListNode, *ListNode) {
	if i > len(arr) {
		return nil, nil
	}
	head := &ListNode{
		Val:  0,
		Next: nil,
	}
	var ans *ListNode 
	curr := head
	for _, v := range arr {
		node := new(ListNode)
		node.Val = v 
		node.Next = nil
		curr.Next = node 
		curr = curr.Next 
		i-- 
		if i == 0 {
			ans = curr 
		}
	}
	return head.Next, ans
}
