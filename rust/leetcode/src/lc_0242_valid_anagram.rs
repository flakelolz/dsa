pub fn is_anagram(s: String, t: String) -> bool {
    if s.len() != t.len() {
        return false;
    }

    let mut map = std::collections::HashMap::<char, i32>::new();

    for c in s.chars() {
        map.entry(c)
            .and_modify(|counter| *counter += 1)
            .or_insert(1);
    }

    for c in t.chars() {
        match map.get_mut(&c) {
            Some(counter) if *counter > 0 => *counter -= 1,
            _ => return false,
        }
    }

    true
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn is_anagram_1() {
        assert!(is_anagram("anagram".to_string(), "nagaram".to_string()));
    }

    #[test]
    fn is_anagram_2() {
        assert!(!is_anagram("rat".to_string(), "car".to_string()));
    }

    #[test]
    fn is_anagram_3() {
        assert!(is_anagram("lucas".to_string(), "claus".to_string()));
    }
}
