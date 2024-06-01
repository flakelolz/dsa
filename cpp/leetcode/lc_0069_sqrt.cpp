int sqrt(int x) {
    int left = 0;
    int right = x;
    int res = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid > x / mid) {
            right = mid - 1;
        } else if (mid < x / mid) {
            left = mid + 1;
            res = mid;
        } else {
            return mid;
        }
    }

    return res;
}
