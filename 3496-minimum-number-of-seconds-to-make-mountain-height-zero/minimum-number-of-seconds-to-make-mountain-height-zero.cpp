class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        long long l = 1, r = 1e18, mid = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (isPossible(workerTimes, mountainHeight, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    bool isPossible(vector<int>& workerTimes, int mountainHeight,
                    long long allocated) {
        long long tred = 0;
        for (auto it : workerTimes) {
            long long l = 1, r = mountainHeight;
            while (l <= r) {
                long long mid = (l + r) / 2;
                long long treq = (mid * (mid + 1) / 2) * it;
                if (treq <= allocated)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            tred += r;
            if (tred >= mountainHeight)
                break;
        }
        return tred >= mountainHeight;
    }
};