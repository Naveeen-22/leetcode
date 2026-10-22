class Solution {
private:
    unordered_map<int, int> mpp;
    int memo[2005][2005]; // Or use an unordered_map for state memoization

    bool f(int index, int k, vector<int>& stones) {
        if (index == stones.size() - 1) return true;
        
        // Using a safe lookup or standard memoization approach
        // (For simplicity and safety against large k, unordered_map<long long, int> is best)
        
        for (int i = k - 1; i <= k + 1; i++) {
            if (i > 0) {
                int nextPos = stones[index] + i;
                if (mpp.find(nextPos) != mpp.end()) {
                    if (f(mpp[nextPos], i, stones)) return true;
                }
            }
        }
        return false;
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] - stones[0] != 1) return false;
        
        mpp.clear();
        for (int i = 0; i < n; i++) {
            mpp[stones[i]] = i;
        }
        
        // Using the hash-set based DP approach prevents any k-size overflow completely:
        unordered_map<int, unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        dp[stones[0]].insert(0);
        
        for (int i = 0; i < n; i++) {
            int curr = stones[i];
            for (int jump : dp[curr]) {
                for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {
                    if (nextJump > 0 && dp.count(curr + nextJump)) {
                        dp[curr + nextJump].insert(nextJump);
                    }
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};