pub fn can_construct(ransom_note: String, magazine: String) -> bool {
    let mut map = std::collections::HashMap::new();

    for c in magazine.chars() {
        map.entry(c).and_modify(|x| *x += 1).or_insert(1);
    }

    for c in ransom_note.chars() {
        match map.get_mut(&c) {
            Some(x) if x > &mut 0 => *x -= 1,
            _ => return false,
        }
    }

    true
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn can_contruct_1() {
        let ransom_note = "a".to_string();
        let magazine = "b".to_string();

        assert!(!can_construct(ransom_note, magazine));
    }

    #[test]
    fn can_contruct_2() {
        let ransom_note = "aa".to_string();
        let magazine = "ab".to_string();

        assert!(!can_construct(ransom_note, magazine));
    }

    #[test]
    fn can_contruct_3() {
        let ransom_note = "aa".to_string();
        let magazine = "aab".to_string();

        assert!(can_construct(ransom_note, magazine));
    }
}
