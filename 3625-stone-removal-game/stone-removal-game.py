class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        stones = 10
        alice_turn = True
        while n>= stones:
            n = n - stones
            stones = stones - 1
            alice_turn = not alice_turn
        return not alice_turn    