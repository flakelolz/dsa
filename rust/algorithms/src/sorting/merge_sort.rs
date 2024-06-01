pub fn merge(arr: &mut [i32], left: usize, mid: usize, right: usize) {
    let left_arr = &arr[left..=mid].to_owned();
    let right_arr = &arr[mid + 1..=right].to_owned();

    let mut i = 0;
    let mut j = 0;

    #[allow(clippy::needless_range_loop)]
    for k in left..=right {
        if i < left_arr.len() && j < right_arr.len() {
            if left_arr[i] < right_arr[j] {
                arr[k] = left_arr[i];
                i += 1;
            } else {
                arr[k] = right_arr[j];
                j += 1;
            }
        } else if i >= left_arr.len() {
            arr[k] = right_arr[j];
            j += 1;
        } else {
            arr[k] = left_arr[i];
            i += 1;
        }
    }
}

pub fn merge_sort(arr: &mut [i32], left: usize, right: usize) {
    if left < right {
        let mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn merge_test() {
        let mut arr = [1, 3, 7, 8, 2, 4, 5, 6];

        merge(&mut arr, 0, 3, 7);
        let result = [1, 2, 3, 4, 5, 6, 7, 8];

        assert_eq!(arr, result);
    }

    #[test]
    fn merge_sort_test() {
        let mut arr = [1, 4, 6, 48, 2, 7, 5, 11, 24, 32];
        let left = 0;
        let right = arr.len() - 1;

        merge_sort(&mut arr, left, right);

        let result = [1, 2, 4, 5, 6, 7, 11, 24, 32, 48];

        assert_eq!(arr, result);
    }
}
