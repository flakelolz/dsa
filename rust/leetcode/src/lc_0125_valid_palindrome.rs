pub fn is_palindrome(s: String) -> bool {
    let result = s
        .to_lowercase()
        .chars()
        .filter(|c| c.is_alphanumeric())
        .collect::<String>();

    result == result.chars().rev().collect::<String>()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn valid_palindrome_1() {
        let s = "A man, a plan, a canal: Panama".to_string();
        assert!(is_palindrome(s));
    }

    #[test]
    fn valid_palindrome_2() {
        let s = "race a car".to_string();
        assert!(!is_palindrome(s));
    }

    #[test]
    fn valid_palindrome_3() {
        let s = " ".to_string();
        assert!(is_palindrome(s));
    }
}
