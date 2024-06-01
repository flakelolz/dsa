pub fn binary_search(array: &[i32], target: i32) -> Option<usize> {
    let mut lo = 0;
    let mut hi = array.len();

    while lo < hi {
        let mid = lo + (hi - lo) / 2;
        let value = array[mid];

        match value.cmp(&target) {
            std::cmp::Ordering::Equal => return Some(mid),
            std::cmp::Ordering::Less => lo = mid + 1,
            std::cmp::Ordering::Greater => hi = mid,
        };
    }

    None
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn binary_search_some() {
        let array = [12, 23, 34, 45, 56, 67, 78, 89, 90, 123];
        let target = 67;
        let result = binary_search(&array, target);

        assert_eq!(result, Some(5));
    }

    #[test]
    fn binary_search_none() {
        let array = [12, 23, 34, 45, 56, 67, 78, 89, 90, 123];
        let target = 100;
        let result = binary_search(&array, target);

        assert_eq!(result, None);
    }
}
