pub fn selection_sort_iter(items: &mut [i32]) {
    for i in 0..items.len() {
        let smallest = items[i..]
            .iter()
            .enumerate()
            .min_by_key(|&(_, v)| v)
            .map(|(j, _)| i + j)
            .expect("slice is non-empty");

        if i != smallest {
            items.swap(i, smallest);
        }
    }
}

pub fn selection_sort(items: &mut [i32]) {
    for i in 0..items.len() {
        let mut smallest = i;

        for j in (i + 1)..items.len() {
            if items[j] < items[smallest] {
                smallest = j;
            }
        }

        if i != smallest {
            items.swap(i, smallest);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn selection_sort_iter_test() {
        let mut arr = [1, 3, 2, 9, 1, 6, 0];
        let result = [0, 1, 1, 2, 3, 6, 9];
        selection_sort_iter(&mut arr);

        assert_eq!(arr, result);
    }

    #[test]
    fn selection_sort_test() {
        let mut arr = [1, 3, 2, 9, 1, 6, 0];
        let result = [0, 1, 1, 2, 3, 6, 9];
        selection_sort(&mut arr);

        assert_eq!(arr, result);
    }
}
