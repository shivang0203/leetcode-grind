class Solution {
public:
    void dfs(int pre, int cur, vector<vector<int>> &g, vector<vector<int>> &par, vector<int> &ans, string &s) {
        par[s[cur] - 'a'].push_back(cur);
        for (auto &x: g[cur]) {
            dfs(cur, x, g, par, ans, s);
        }
        par[s[cur] - 'a'].pop_back();
        ans[cur] += 1;
        if (par[s[cur] - 'a'].size() > 0) {
            int prev = par[s[cur] - 'a'].back();
            ans[prev] += ans[cur];
        } else if (pre != -1) {
            ans[pre] += ans[cur];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) g[parent[i]].push_back(i);

        vector<vector<int>> par(26);
        vector<int> ans(n, 0);
        dfs(-1, 0, g, par, ans, s);
        return ans;
    }
};