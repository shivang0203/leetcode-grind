class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> ans(queries.size(), 0);
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        int count = 0;
        for (auto &[q, index] : sortedQueries) {
            while (!minHeap.empty() && minHeap.top().first < q) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();
                count++;

                int r = pos.first, c = pos.second;
                for (auto &[dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        minHeap.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            ans[index] = count;
        }

        return ans;
    }
};