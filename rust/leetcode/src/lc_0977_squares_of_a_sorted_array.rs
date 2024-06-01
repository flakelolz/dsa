pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
    let mut left = 0;
    let mut right = nums.len() - 1;
    let mut result = vec![];

    while left <= right {
        let l = nums[left] * nums[left];
        let r = nums[right] * nums[right];

        if r > l {
            result.push(r);
            right -= 1;
        } else {
            result.push(l);
            left += 1;
        }
    }

    result.into_iter().rev().collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sorted_squares_1() {
        let result = sorted_squares(vec![-4, -1, 0, 3, 10]);
        assert_eq!(result, vec![0, 1, 9, 16, 100]);
    }

    #[test]
    fn sorted_squares_2() {
        let result = sorted_squares(vec![-7, -3, 2, 3, 11]);
        assert_eq!(result, vec![4, 9, 9, 49, 121]);
    }

    #[test]
    fn sorted_squares_3() {
        let result = sorted_squares(vec![-5, -3, -2, -1]);
        assert_eq!(result, vec![1, 4, 9, 25]);
    }
}
