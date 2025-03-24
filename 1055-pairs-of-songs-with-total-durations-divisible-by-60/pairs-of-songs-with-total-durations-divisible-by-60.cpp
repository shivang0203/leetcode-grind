class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int c = 0;
        for (int i : time) {
            int r1 = i % 60;
            int r2 = (60 - r1) % 60;
            if (mp.find(r2) != mp.end()) {
                c += mp[r2];
            }
            mp[r1]++;
        }
        return c;
    }
};