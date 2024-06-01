from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
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


solution = Solution()


def test_search_1():
    nums = [-1, 0, 3, 5, 9, 12]
    target = 9
    assert solution.search(nums, target) == 4
