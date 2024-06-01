pub fn search(nums: Vec<i32>, target: i32) -> i32 {
    let mut low = 0;
    let mut high = nums.len();

    while low < high {
        let mid = low + (high - low) / 2;

        match nums[mid].cmp(&target) {
            std::cmp::Ordering::Less => low = mid + 1,
            std::cmp::Ordering::Equal => return mid as i32,
            std::cmp::Ordering::Greater => high = mid,
        }
    }

    -1
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn binary_search_1() {
        assert_eq!(search(vec![-1, 0, 3, 5, 9, 12], 9), 4);
    }

    #[test]
    fn binary_search_2() {
        assert_eq!(search(vec![-1, 0, 3, 5, 9, 12], 2), -1);
    }

    #[test]
    fn binary_search_3() {
        assert_eq!(search(vec![-1, 0, 3, 5, 9, 12], 12), 5);
    }
}
