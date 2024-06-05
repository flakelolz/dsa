from typing import List


def search(nums: List[int], target: int) -> int:
    left = 0
    right = len(nums) - 1

    while left <= right:
        mid = left + ((right - left) // 2)
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        else:
            return mid

    return -1


def test_search_1():
    nums = [-1, 0, 3, 5, 9, 12]
    target = 9
    assert search(nums, target) == 4


def test_search_2():
    nums = [-1, 0, 3, 5, 9, 12]
    target = 2

    assert search(nums, target) == -1
