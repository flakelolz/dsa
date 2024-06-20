from typing import List


def intersection(nums1: List[int], nums2: List[int]) -> List[int]:
    hashset = set(nums1)
    result = []

    for num in nums2:
        if num in hashset:
            result.append(num)
            hashset.remove(num)

    return result


def test_intersection_1():
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]
    assert intersection(nums1, nums2) == [2]


def test_intersection_2():
    nums1 = [4, 9, 5]
    nums2 = [9, 4, 9, 8, 4]
    assert intersection(nums1, nums2) == [9, 4]
