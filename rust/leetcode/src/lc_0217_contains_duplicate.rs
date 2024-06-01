pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let set = std::collections::HashSet::<&i32>::from_iter(&nums);

    set.len() != nums.len()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn contains_duplicate_1() {
        assert!(contains_duplicate(vec![1, 2, 3, 1]));
    }

    #[test]
    fn contains_duplicate_2() {
        assert!(!contains_duplicate(vec![1, 2, 3, 4]));
    }

    #[test]
    fn contains_duplicate_3() {
        assert!(contains_duplicate(vec![1, 1, 1, 3, 3, 4, 3, 2, 4, 2]));
    }
}
