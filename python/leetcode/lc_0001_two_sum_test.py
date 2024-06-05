from typing import List


def twoSum_force(nums: List[int], target: int) -> List[int]:
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []


def twoSum_hashmap(nums: List[int], target: int) -> List[int]:
    hashmap = {}  # key: number, value: index
    for i, n in enumerate(nums):
        diff = target - n
        if diff in hashmap:
            return [hashmap[diff], i]
        hashmap[n] = i
    return []


def test_twoSum_1():
    nums = [2, 7, 11, 15]
    target = 9

    assert twoSum_hashmap(nums, target) == [0, 1]
    assert twoSum_force(nums, target) == [0, 1]


def test_twoSum_2():
    nums = [3, 2, 4]
    target = 6

    assert twoSum_hashmap(nums, target) == [1, 2]
    assert twoSum_force(nums, target) == [1, 2]


def test_twoSum_3():
    nums = [3, 3]
    target = 6

    assert twoSum_hashmap(nums, target) == [0, 1]
    assert twoSum_force(nums, target) == [0, 1]
