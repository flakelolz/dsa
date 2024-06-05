from typing import List


def singleNumber(nums: List[int]) -> int:
    res = 0

    for n in nums:
        res = n ^ res

    return res


def test_singleNumber_1():
    nums = [2, 2, 1]
    assert singleNumber(nums) == 1


def test_singleNumber_2():
    nums = [4, 1, 2, 1, 2]
    assert singleNumber(nums) == 4


def test_singleNumber_3():
    nums = [1]
    assert singleNumber(nums) == 1
