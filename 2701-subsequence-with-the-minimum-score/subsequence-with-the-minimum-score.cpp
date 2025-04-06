class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> pref(n, -1), suff(n, -1);
        int j = 0;
        for (int i = 0; i < m && j < n; ++i) {
            if (s[i] == t[j]) {
                pref[j] = i;
                ++j;
            }
        }
        j = n - 1;
        for (int i = m - 1; i >= 0 && j >= 0; --i) {
            if (s[i] == t[j]) {
                suff[j] = i;
                --j;
            }
        }

        int result = n;
        if (pref[n - 1] != -1)
            result = 0;

        for (int i = 0; i < n; i++)
            if (pref[i] != -1)
                result = min(result, n - i);
        for (int i = n - 1; i >= 0; i--)
            if (suff[i] != -1)
                result = min(result, i);
        for (int i = 0; i < n - 1; ++i) {
            if (pref[i] == -1)
                continue;
            int lo = i + 1, hi = n, mid;
            while (hi - lo > 1) {
                mid = (hi + lo) / 2;
                if (suff[mid] <= pref[i])
                    lo = mid;
                else
                    hi = mid;
            }
            result = min(result, hi - i - 1);
        }

        return result;
    }
};