class Solution {
public:
    int numTrees(int n) {
        int dp[++n];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n - 1];
    }
};

//LeetCode Link: https://leetcode.com/problems/unique-binary-search-trees/
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
//Memory Usage: 6 MB, less than 64.63% of C++ online submissions for Unique Binary Search Trees.
