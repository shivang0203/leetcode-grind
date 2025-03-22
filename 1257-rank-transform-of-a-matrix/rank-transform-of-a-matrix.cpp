class UnionFind {
public:
    unordered_map<int, int> parent;
    int Find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = Find(parent[u]);
    }
    void Union(int u, int v) {
        if (parent.count(u) == 0)
            parent[u] = u;
        if (parent.count(v) == 0)
            parent[v] = v;
        int pu = Find(u), pv = Find(v);
        if (pu != pv)
            parent[pu] = pv;
    }
    unordered_map<int, vector<int>> getGroups() {
        unordered_map<int, vector<int>> groups;
        for (auto const& [u, _] : parent)
            groups[Find(u)].push_back(u);
        return groups;
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<pair<int, int>>> groupByValue;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                groupByValue[matrix[r][c]].push_back({r, c});

        vector<int> rank(m + n, 0);
        for (auto const& [_, cells] : groupByValue) {
            UnionFind uf;
            for (auto const& [r, c] : cells)
                uf.Union(r, c + m);

            for (auto const& [_, group] : uf.getGroups()) {
                int maxRank = 0;
                for (int i : group)
                    maxRank = max(maxRank, rank[i]);
                for (int i : group)
                    rank[i] = maxRank + 1;
            }
            for (auto const& [r, c] : cells)
                matrix[r][c] = rank[r];
        }
        return matrix;
    }
};