class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while right > left and not s[right].isalnum():
                right -= 1
            if s[left].lower() != s[right].lower():
                return False
            left, right = left + 1, right - 1

        return True


def test_isPalindrome_1():
    s = "A man, a plan, a canal: Panama"
    assert Solution().isPalindrome(s) is True


def test_isPalindrome_2():
    s = "race a car"
    assert Solution().isPalindrome(s) is False


def test_isPalindrome_3():
    s = ".,"
    assert Solution().isPalindrome(s) is True
