using ll = long long;
class Solution {
public:
    long long maximumSubsequenceCount(string& text, string& pattern) {
        int n = text.size(), ca = 0, cb = 0;
        char a = pattern[0], b = pattern[1];

        for (char c : text)
            ca += c == a, cb += c == b;

        ll d = max(ca, cb), ans = 0;
        for (char c : text) {
            cb -= c == b;
            if (c == a)
                ans += cb;
        }
        return ans + d;
    }
};