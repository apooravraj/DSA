class Solution {
public:

int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr, vector<vector<int>>& t) {
    if (idx == nums.size()) {
        if (currOr == maxOr)
            return 1;
        return 0;
    }

    if (t[idx][currOr] != -1) {
        return t[idx][currOr];
    }

    int takeCount = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr, t);
    int notTakeCount = countSubsets(idx + 1, currOr, nums, maxOr, t);

    return t[idx][currOr] = takeCount + notTakeCount;
}

int countMaxOrSubsets(vector<int>& nums) {
    int maxOr = 0;
    for (int &num : nums) {
        maxOr |= num;
    }
    int n = nums.size();

    vector<vector<int>> t(n + 1, vector<int>(maxOr + 1, -1));
    int currOr = 0;

    return countSubsets(0, currOr, nums, maxOr, t);
}
};
