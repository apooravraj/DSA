class Solution {
public:
    // Fenwick Tree (BIT) helper class
    class FenwickTree {
        vector<int> tree;
        int n;
    public:
        FenwickTree(int size) {
            n = size + 2;
            tree.resize(n, 0);
        }

        void update(int index, int value) {
            index++;  // 1-based indexing
            while (index < n) {
                tree[index] += value;
                index += index & -index;
            }
        }

        int query(int index) {
            index++;  // 1-based indexing
            int result = 0;
            while (index > 0) {
                result += tree[index];
                index -= index & -index;
            }
            return result;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);

        // Map each number to its index in nums2
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i;
        }

        // Transform nums1 to the positions in nums2
        vector<int> transformed(n);
        for (int i = 0; i < n; ++i) {
            transformed[i] = pos[nums1[i]];
        }

        // Left pass: Count how many elements are smaller to the left
        FenwickTree leftTree(n);
        vector<int> leftCount(n);
        for (int i = 0; i < n; ++i) {
            leftCount[i] = leftTree.query(transformed[i] - 1);
            leftTree.update(transformed[i], 1);
        }

        // Right pass: Count how many elements are greater to the right
        FenwickTree rightTree(n);
        long long result = 0;
        for (int i = n - 1; i >= 0; --i) {
            int rightCount = rightTree.query(n - 1) - rightTree.query(transformed[i]);
            result += (long long)leftCount[i] * rightCount;
            rightTree.update(transformed[i], 1);
        }

        return result;
    }
};
