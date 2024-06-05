from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Time Complexity: O(n+m)
# Space Complexity: O(1)
def mergeTwoLists(
    list1: Optional[ListNode], list2: Optional[ListNode]
) -> Optional[ListNode]:
    dummy = ListNode()
    tail = dummy

    while list1 and list2:
        if list1.val < list2.val:
            tail.next = list1
            list1 = list1.next
        else:
            tail.next = list2
            list2 = list2.next
        tail = tail.next

    if list1:
        tail.next = list1
    elif list2:
        tail.next = list2

    return dummy.next


def checker(list1, list2):
    while list1 and list2:
        if list1.val != list2.val:
            return False
        list1 = list1.next
        list2 = list2.next
    return True


def test_mergeTwoLists_1():
    list1 = ListNode(1)
    list1.next = ListNode(2)
    list1.next.next = ListNode(4)

    list2 = ListNode(1)
    list2.next = ListNode(3)
    list2.next.next = ListNode(4)

    answer = ListNode(1)
    answer.next = ListNode(1)
    answer.next.next = ListNode(2)
    answer.next.next.next = ListNode(3)
    answer.next.next.next.next = ListNode(4)
    answer.next.next.next.next.next = ListNode(4)

    assert checker(mergeTwoLists(list1, list2), answer) is True


def test_mergeTwoLists_2():
    list1 = ListNode()
    list2 = ListNode()

    answer = ListNode()

    assert checker(mergeTwoLists(list1, list2), answer) is True


def test_mergeTwoLists_3():
    list1 = ListNode()
    list2 = ListNode(0)

    answer = ListNode(0)

    assert checker(mergeTwoLists(list1, list2), answer) is True
