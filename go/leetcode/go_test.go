package leetcode

import (
	// "fmt"
	"testing"
)

func TestMergeTwoLists(t *testing.T) {
	l1 := &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 4, Next: nil}}}
	l2 := &ListNode{Val: 1, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: nil}}}
	l3 := &ListNode{Val: 1, Next: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 4, Next: nil}}}}}}

	result := mergeTwoLists(l1, l2)
	_ = result

	for l3 != nil {
		if result.Val != l3.Val {
			t.Fail()
		}

		l3 = l3.Next
		result = result.Next
	}
}
