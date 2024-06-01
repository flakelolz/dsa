// PERF: For BTreeMap is only for having a deterministic output
//       in testing. In the actual answer, HashMap was used.
pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
    let mut map = std::collections::BTreeMap::<[i32; 26], Vec<String>>::new();

    for s in strs {
        let mut count = [0; 26];

        for c in s.chars() {
            count[c as usize - 'a' as usize] += 1;
        }

        map.entry(count).or_default().push(s);
    }

    map.into_values().collect()
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::*;

    #[test]
    fn group_anagrams_1() {
        let result = group_anagrams(s!["eat", "tea", "tan", "ate", "nat", "bat"]);
        assert_eq!(
            result,
            vec![s!["tan", "nat"], s!["eat", "tea", "ate"], s!["bat"]]
        );
    }

    #[test]
    fn group_anagrams_2() {
        let result = group_anagrams(s![""]);
        assert_eq!(result, vec![s![""]]);
    }

    #[test]
    fn group_anagrams_3() {
        let result = group_anagrams(s!["a"]);
        assert_eq!(result, vec![s!["a"]]);
    }
}
