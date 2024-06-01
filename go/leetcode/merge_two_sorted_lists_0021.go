package leetcode

type ListNode struct {
	Next *ListNode
	Val  int
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	newHead := &ListNode{}
	cur := newHead
	for l1 != nil || l2 != nil {
		if (l1 != nil && l2 != nil && l1.Val <= l2.Val) || l2 == nil {
			cur.Next = l1
			l1 = l1.Next
		} else if l2 != nil {
			cur.Next = l2
			l2 = l2.Next
		}
		cur = cur.Next
	}

	return newHead.Next
}

func AddTwo(a, b int) int {
	return a + b
}
