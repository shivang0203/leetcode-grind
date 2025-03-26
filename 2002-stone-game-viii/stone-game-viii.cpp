class Solution {
    int n;
    int rec(int i, vector<int> &p, vector<int> &cache){
        if(i == n-2) return p[i+1];

        if(cache[i] != -1) return cache[i];
        int alice_cont = rec(i+1, p, cache);
        int alice_done = p[i+1] - rec(i+1, p, cache);

        return cache[i] = max(alice_cont, alice_done);
    }
public:
    int stoneGameVIII(vector<int>& p) {
        n = p.size();
        for (int i = 1; i < n; i++) p[i] += p[i-1];
        vector<int> cache(n, -1);
        return rec(0,p,cache);
    }
};