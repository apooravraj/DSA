import heapq

class Solution:
    def assignTasks(self, servers, tasks):
        busy = []
        idle = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(idle)
        ans = []
        ts = 0

        def release(time):
            while busy and busy[0][0] <= time:
                _, idx = heapq.heappop(busy)
                heapq.heappush(idle, (servers[idx], idx))

        for i, d in enumerate(tasks):
            ts = max(ts, i)
            release(ts)
            if not idle:
                ts = busy[0][0]
                release(ts)

            _, idx = heapq.heappop(idle)
            ans.append(idx)
            heapq.heappush(busy, (ts + d, idx))

        return ans