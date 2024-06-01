pub fn max_profit(prices: Vec<i32>) -> i32 {
    let mut left = 0;
    let mut right = 1;
    let mut max = 0;

    while right < prices.len() {
        if prices[left] < prices[right] {
            let profit = prices[right] - prices[left];
            max = std::cmp::max(max, profit);
        } else {
            left = right;
        }
        right += 1;
    }
    max
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn max_profit_1() {
        assert_eq!(max_profit(vec![7, 1, 5, 3, 6, 4]), 5);
    }

    #[test]
    fn max_profit_2() {
        assert_eq!(max_profit(vec![7, 6, 4, 3, 1]), 0);
    }

    #[test]
    fn max_profit_3() {
        assert_eq!(max_profit(vec![2, 4, 1]), 2);
    }
}
