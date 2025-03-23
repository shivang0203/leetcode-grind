class Solution {
public:
    int countCollisions(string directions) {
        int a = -1;
        int res = 0;

        for (int i = 0; i < directions.size(); i++) {
            if (directions[i] == 'R') {
                if (a == -1) {
                    a = 1;
                } else {
                    a++;
                }

            } else if (directions[i] == 'L' && a >= 1) {
                res += a + 1;
                a = 0;
            } else if (directions[i] == 'L' && a == 0) {
                res += 1;
                a = 0;
            } else if (directions[i] == 'S' && a >= 1) {
                res += a;
                a = 0;
            } else if (directions[i] == 'S') {
                a = 0;
            }
        }
        return res;
    }
};