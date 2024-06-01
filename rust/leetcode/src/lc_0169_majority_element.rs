pub fn majority_element(nums: Vec<i32>) -> i32 {
    let mut map = std::collections::HashMap::new();

    for num in &nums {
        let current = map.entry(num).and_modify(|c| *c += 1).or_insert(1);

        if *current > nums.len() / 2 {
            return *num;
        }
    }

    unreachable!("There is always a majority element in the array")
}

pub fn boyer_moore(nums: Vec<i32>) -> i32 {
    let mut count = 0;
    let mut candidate = 0;

    for num in nums {
        if count == 0 {
            candidate = num;
        }

        count += if num == candidate { 1 } else { -1 };
    }

    candidate
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn majority_element_1() {
        assert_eq!(majority_element(vec![3, 2, 3]), 3);
        assert_eq!(boyer_moore(vec![3, 2, 3]), 3);
    }

    #[test]
    fn majority_element_2() {
        assert_eq!(majority_element(vec![2, 2, 1, 1, 1, 2, 2]), 2);
        assert_eq!(boyer_moore(vec![2, 2, 1, 1, 1, 2, 2]), 2);
    }

    #[test]
    fn majority_element_3() {
        assert_eq!(majority_element(vec![1, 1, 1, 1, 2, 2, 2, 2, 2]), 2);
        assert_eq!(boyer_moore(vec![1, 1, 1, 1, 2, 2, 2, 2, 2]), 2);
    }
}
