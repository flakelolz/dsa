pub fn single_number(nums: Vec<i32>) -> i32 {
    let mut res = 0;
    for num in nums {
        res ^= num;
    }

    res
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn single_number_1() {
        let nums = vec![2, 2, 1];
        assert_eq!(single_number(nums), 1);
    }

    #[test]
    fn single_number_2() {
        let nums = vec![4, 1, 2, 1, 2];
        assert_eq!(single_number(nums), 4);
    }

    #[test]
    fn single_number_3() {
        let nums = vec![1];
        assert_eq!(single_number(nums), 1);
    }
}
