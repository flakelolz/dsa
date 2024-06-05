pub fn max_power(s: String) -> i32 {
    let mut count = 1;
    let mut prev = 0;
    let mut max = 1;

    for i in 1..s.len() {
        if s.chars().nth(i) == s.chars().nth(prev) {
            count += 1;
            max = i32::max(count, max);
        } else {
            count = 1;
            prev = i;
        }
    }

    max
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn max_power_1() {
        let s = String::from("leetcode");
        assert_eq!(max_power(s), 2);
    }

    #[test]
    fn max_power_2() {
        let s = String::from("abbcccddddeeeeedcba");
        assert_eq!(max_power(s), 5);
    }

    #[test]
    fn max_power_3() {
        let s = String::from("cc");
        assert_eq!(max_power(s), 2);
    }
}
