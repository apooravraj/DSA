class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        if (n == 0) return eventTime;

        // Step 1: Sort intervals by startTime
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            intervals.push_back({startTime[i], endTime[i]});
        }
        sort(intervals.begin(), intervals.end());

        // Step 2: Update sorted startTime and endTime
        for (int i = 0; i < n; i++) {
            startTime[i] = intervals[i].first;
            endTime[i] = intervals[i].second;
        }

        // Step 3: Build free time array
        vector<int> freeArray;
        freeArray.push_back(startTime[0]); // Free time before the first event

        for (int i = 1; i < n; i++) {
            freeArray.push_back(startTime[i] - endTime[i - 1]); // Between events
        }

        freeArray.push_back(eventTime - endTime[n - 1]); // After last event

        // Step 4: Sliding window for max sum of at most (k + 1) free intervals
        int i = 0, j = 0, maxSum = 0, currSum = 0;
        int m = freeArray.size();

        while (j < m) {
            currSum += freeArray[j];

            if (j - i + 1 > k + 1) {
                currSum -= freeArray[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;
    }
};

