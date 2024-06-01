pub fn move_zeroes(nums: &mut [i32]) {
    let mut left = 0;

    for right in 0..nums.len() {
        if nums[right] != 0 {
            nums.swap(left, right);
            left += 1;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn move_zeroes_1() {
        let mut nums = vec![0, 1, 0, 3, 12];
        move_zeroes(&mut nums);

        assert_eq!(nums, vec![1, 3, 12, 0, 0]);
    }

    #[test]
    fn move_zeroes_2() {
        let mut nums = vec![0];
        move_zeroes(&mut nums);

        assert_eq!(nums, vec![0]);
    }

    #[test]
    fn move_zeroes_3() {
        let mut nums = vec![0, 0, 10, 0];
        move_zeroes(&mut nums);

        assert_eq!(nums, vec![10, 0, 0, 0]);
    }
}
