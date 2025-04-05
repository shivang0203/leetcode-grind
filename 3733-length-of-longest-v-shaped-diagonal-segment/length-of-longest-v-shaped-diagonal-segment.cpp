class Solution {
public:
    int n, m;
    int dp[501][501][4][2];

    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, -1, 1};

    bool isValidTurn(int oldDir, int newDir) {
        return (newDir != oldDir) && ((oldDir + 1) % 4 == newDir);
    }

    int solve(int i, int j, int curr, int dir, int turn,
              vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != curr) {
            return 0;
        }

        if (dp[i][j][dir][turn] != -1) {
            return dp[i][j][dir][turn];
        }

        int maxLength =
            1 + solve(i + dx[dir], j + dy[dir], 2 - curr, dir, turn, grid);
        if (turn == 0) {
            for (int newDir = 0; newDir < 4; newDir++) {
                if (isValidTurn(dir, newDir)) {
                    maxLength =
                        max(maxLength, 1 + solve(i + dx[newDir], j + dy[newDir],
                                                 2 - curr, newDir, 1, grid));
                }
            }
        }

        return dp[i][j][dir][turn] = maxLength;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        maxLength =
                            max(maxLength, 1 + solve(i + dx[dir], j + dy[dir],
                                                     2, dir, 0, grid));
                    }
                }
            }
        }

        return maxLength;
    }
};