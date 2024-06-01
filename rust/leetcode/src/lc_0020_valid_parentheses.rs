pub fn is_valid(s: String) -> bool {
    let mut stack = String::new();

    for c in s.chars() {
        match c {
            '(' => stack.push(')'),
            '{' => stack.push('}'),
            '[' => stack.push(']'),
            ')' | '}' | ']' => {
                if stack.is_empty() || stack.pop().unwrap() != c {
                    return false;
                }
            }
            _ => (),
        }
    }

    stack.is_empty()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn valid_parentheses_1() {
        assert!(is_valid(String::from("()")));
    }

    #[test]
    fn valid_parentheses_2() {
        assert!(is_valid(String::from("()[]{}")));
    }

    #[test]
    fn valid_parentheses_3() {
        assert!(!is_valid(String::from("(]")));
    }
}
