class Solution:
    def maxNumOfSubstrings(self, s):
        n = len(s)

        first = [n] * 26
        last = [-1] * 26

        # Find first and last occurrence of every character
        for i in range(n):
            ch = ord(s[i]) - ord('a')

            if first[ch] == n:
                first[ch] = i

            last[ch] = i

        intervals = []

        # Build valid intervals
        for ch in range(26):
            if last[ch] == -1:
                continue

            start = first[ch]
            end = last[ch]

            valid = True
            i = start

            # Keep checking even when end gets expanded
            while i <= end:
                current = ord(s[i]) - ord('a')

                # This character has an occurrence before start
                if first[current] < start:
                    valid = False
                    break

                # Include all occurrences of this character
                end = max(end, last[current])

                i += 1

            if valid:
                intervals.append((start, end))

        # Sort by ending position
        intervals.sort(key=lambda x: (x[1], x[1] - x[0]))

        answer = []
        previous_end = -1

        # Greedily choose non-overlapping intervals
        for start, end in intervals:
            if start > previous_end:
                answer.append(s[start:end + 1])
                previous_end = end

        return answer