pub fn insertion_sort(items: &mut [i32]) {
    for i in 1..items.len() {
        let temp = items[i];
        let mut j = (i - 1) as i32;

        while j > -1 && temp < items[j as usize] {
            items[j as usize + 1] = items[j as usize];
            items[j as usize] = temp;
            j -= 1;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn insertion_sort_test() {
        let mut arr = [1, 3, 2, 9, 1, 6, 0];
        let result = [0, 1, 1, 2, 3, 6, 9];
        insertion_sort(&mut arr);

        assert_eq!(arr, result);
    }
}
