class Solution {
public:
    int n, sum;
    int dp[32][4000];
    int f(vector<int>& v, int i, int target) {
        if (i >= n)
            return abs(2 * target - sum);
        if (dp[i][target] != -1)
            return dp[i][target];
        return dp[i][target] = min(f(v, i + 1, target + v[i]), 
                                        f(v, i + 1, target));
    }

    int lastStoneWeightII(vector<int>& stones) {
        sum = accumulate(stones.begin(), stones.end(), 0), n = stones.size();
        n = stones.size();
        memset(dp, -1, sizeof(dp));
        return f(stones, 0, 0);
    }
};