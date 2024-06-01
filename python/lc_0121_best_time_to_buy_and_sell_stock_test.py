from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left, right = 0, 1
        max_profit = 0

        while right < len(prices):
            # profitable?
            if prices[left] < prices[right]:
                profit = prices[right] - prices[left]
                max_profit = max(max_profit, profit)
            else:
                left = right
            right += 1

        return max_profit


solution = Solution()


def test_maxProfit_1():
    prices = [7, 1, 5, 3, 6, 4]
    assert solution.maxProfit(prices) == 5


def test_maxProfit_2():
    prices = [7, 6, 4, 3, 1]
    assert solution.maxProfit(prices) == 0
