from typing import List
from typing import Optional


def binary_search(arr: List[int], target: int) -> Optional[int]:
    low = 0
    high = len(arr)

    while low < high:
        mid = low + (high - low) // 2
        if arr[mid] < target:
            low = mid + 1
        elif arr[mid] > target:
            high = mid
        else:
            return mid

    return None


if __name__ == "__main__":
    arr = [12, 23, 34, 45, 56, 67, 78, 89, 90, 123]
    target = 67
    print(binary_search(arr, target))
