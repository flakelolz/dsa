pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut map = std::collections::HashMap::<i32, i32>::new();

    for (i, n) in nums.iter().enumerate() {
        let diff = target - n;
        let index = map.get(&diff);

        if let Some(result) = index {
            return vec![*result, i as i32];
        }

        map.insert(*n, i as i32);
    }

    vec![]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn two_sum_1() {
        assert_eq!(two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
    }

    #[test]
    fn two_sum_2() {
        assert_eq!(two_sum(vec![3, 2, 4], 6), vec![1, 2]);
    }

    #[test]
    fn two_sum_3() {
        assert_eq!(two_sum(vec![3, 3], 6), vec![0, 1]);
    }
}
