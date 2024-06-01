#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    #[allow(unused)]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn merge_two_lists(
    mut list1: Option<Box<ListNode>>,
    mut list2: Option<Box<ListNode>>,
) -> Option<Box<ListNode>> {
    let mut temp = &mut list1;
    while list2.is_some() {
        if temp.is_none() || list2.as_ref()?.val < temp.as_ref()?.val {
            std::mem::swap(temp, &mut list2);
        }
        temp = &mut temp.as_mut()?.next;
    }
    list1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn merge_two_lists_1() {
        let mut l1 = ListNode::new(1);
        l1.next = Some(Box::new(ListNode::new(2)));
        l1.next.as_mut().unwrap().next = Some(Box::new(ListNode::new(4)));

        let mut l2 = ListNode::new(1);
        l2.next = Some(Box::new(ListNode::new(3)));
        l2.next.as_mut().unwrap().next = Some(Box::new(ListNode::new(4)));

        let merged = merge_two_lists(Some(Box::new(l1)), Some(Box::new(l2)));

        #[rustfmt::skip]
        assert_eq!(merged.clone().unwrap().val, 1);
        #[rustfmt::skip]
        assert_eq!(merged.clone().unwrap().next.unwrap().val, 1);
        #[rustfmt::skip]
        assert_eq!(merged.clone().unwrap().next.unwrap().next.unwrap().val, 2);
        #[rustfmt::skip]
        assert_eq!(merged.clone().unwrap().next.unwrap().next.unwrap().next.unwrap().val, 3);
        #[rustfmt::skip]
        assert_eq!(merged.clone().unwrap().next.unwrap().next.unwrap().next.unwrap().next.unwrap().val, 4);
        #[rustfmt::skip]
        assert_eq!(merged.clone().unwrap().next.unwrap().next.unwrap().next.unwrap().next.unwrap().val, 4);
        #[rustfmt::skip]
        assert_eq!(merged.unwrap().next.unwrap().next.unwrap().next.unwrap().next.unwrap().next.unwrap().next, None);
    }
}
