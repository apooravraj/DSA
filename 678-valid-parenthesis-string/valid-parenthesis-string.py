class Solution:
    def checkValidString(self, s: str) -> bool:
        low = 0
        high = 0

        for ch in s:
            if ch == '(':
                low = low + 1
                high = high + 1
            elif ch == ')':
                if low > 0:
                    low = low - 1
                high = high - 1
            else:
                if low > 0:
                    low = low - 1
                high = high + 1

            if high < 0:
                return False

        return low == 0