class Solution {
public:
    bool isPrintable(vector<vector<int>>& target) {
        int m = target.size(), n = target[0].size();
        int maxColor = -1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
            maxColor = max(maxColor, target[i][j]);
        }

        vector<pair<int, int>> rowBounds(maxColor + 1);
        vector<pair<int, int>> colBounds(maxColor + 1);

        for(int i=0; i<=maxColor; i++){
            rowBounds[i].first = INT_MAX;
            rowBounds[i].second = INT_MIN;
            colBounds[i].first = INT_MAX;
            colBounds[i].second = INT_MIN;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int c = target[i][j];
                rowBounds[c].first = min(rowBounds[c].first, i);
                rowBounds[c].second = max(rowBounds[c].second, i);
                colBounds[c].first = min(colBounds[c].first, j);
                colBounds[c].second = max(colBounds[c].second, j);
            }
        }

        vector<vector<bool>> preReq(maxColor + 1, vector<bool> (maxColor + 1, false));
        for(int col=1; col<=maxColor; col++){
            int rLow = rowBounds[col].first, rHigh = rowBounds[col].second;
            int cLow = colBounds[col].first, cHigh = colBounds[col].second;

            for(int i=rLow; i<=rHigh; i++){
                for(int j=cLow; j<=cHigh; j++){
                    int val = target[i][j];
                    preReq[col][val] = true; 
                }
            }
        }

        vector<int> indegree(maxColor + 1, 0);
        for(int i=1; i<=maxColor; i++){
            for(int j=1; j<=maxColor; j++){
                if(i != j && preReq[i][j])
                ++indegree[j];
            }
        }

        int count = 0;
        queue<int> q;
        for(int i=1; i<=maxColor; i++){
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ++count;
            for(int i=1; i<=maxColor; i++){
                if(!preReq[node][i])
                continue;

                --indegree[i];
                if(indegree[i] == 0)
                q.push(i);
            }
        }

        return (count == maxColor) ? true : false;
    }
};