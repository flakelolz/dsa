def maxPower(s: str) -> int:
    prev = s[0]
    count = 1
    max_count = 1

    for i in range(1, len(s)):
        if prev == s[i]:
            count += 1
            max_count = max(max_count, count)
        else:
            count = 1
            prev = s[i]

    return max_count


def test_maxPower_1():
    assert maxPower("leetcode") == 2


def test_maxPower_2():
    assert maxPower("abbcccddddeeeeedcba") == 5


def test_maxPower_3():
    assert maxPower("cc") == 2
