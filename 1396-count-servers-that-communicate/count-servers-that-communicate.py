class Solution(object):
    def countServers(self, grid):
        n = len(grid)
        m = len(grid[0])

        countRow = [0] * n
        countCol = [0] * m

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    countRow[i] += 1
                    countCol[j] += 1

        res = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and (countRow[i] > 1 or countCol[j] > 1):
                    res += 1

        return res