class Solution {
public:
    bool solve(vector<int>& d, int speed, double hour) {
        int time = 0;
        for (int i = 0; i < d.size() - 1; i++) {
            time += (d[i] / speed) + (d[i] % speed != 0);
            if (time >= hour)
                return 0;
        }
        double last = (double)d.back() / (double)speed;

        return (last + (double)time <= hour);
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() - 1 >= hour)
            return -1;
        int l = 1, r = 1e7, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (solve(dist, mid, hour))
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }
};