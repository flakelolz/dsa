pub fn bubble_sort(arr: &mut [i32]) {
    for i in 0..arr.len() {
        for j in 0..arr.len() - 1 - i {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bubble_sort_test() {
        let mut arr = [1, 3, 2, 9, 1, 6, 0];
        let result = [0, 1, 1, 2, 3, 6, 9];
        bubble_sort(&mut arr);

        assert_eq!(arr, result);
    }
}
