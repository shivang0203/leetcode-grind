class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int x1 = startPos[0], y1 = startPos[1], x2 = homePos[0],
            y2 = homePos[1], cost = 0;
        while (x1 < x2) {
            x1++;
            cost += rowCosts[x1];
        }
        while(y1 < y2){
            y1++;
            cost += colCosts[y1];
        }
        while(x1 > x2){
            x1--;
            cost += rowCosts[x1];
        }
        while(y1 > y2){
            y1--;
            cost += colCosts[y1];
        }
        return cost;
    }
};