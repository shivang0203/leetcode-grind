class Solution {
public:
    int countPyramids(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> left(n, vector<int>(m, -1)),
            right(n, vector<int>(m, m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) {
                    left[i][j] = j;
                    continue;
                }
                int val = j - 1;
                while (val != -1 && a[i][j] <= a[i][val])
                    val = left[i][val];
                left[i][j] = val;
            }
        for (int i = 0; i < n; i++)
            for (int j = m - 1; j >= 0; j--) {
                if (a[i][j] == 0) {
                    right[i][j] = j;
                    continue;
                }
                int val = j + 1;
                while (val != m && a[i][j] <= a[i][val])
                    val = right[i][val];
                right[i][j] = val;
            }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0)
                    continue;
                int up = 1, r = 0;
                while (i - up >= 0 && a[i - up][j] == 1 && j - up >= 0 &&
                       j + up < m && right[i - up][j] > j + up &&
                       left[i - up][j] < j - up) {
                    up++;
                    r++;
                }
                ans += r;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0)
                    continue;
                int down = 1, r = 0;
                while (i + down < n && a[i + down][j] == 1 && j - down >= 0 &&
                       j + down < m && right[i + down][j] > j + down &&
                       left[i + down][j] < j - down) {
                    down++;
                    r++;
                }
                ans += r;
            }
        return ans;
    }
};