class Solution {
    int mod;
    long long power(long long a, long long b) {
        if (b == 0) return 1;
        long long res = power(a, b/2) % mod;
        res = (res * res) % mod;
        if (b % 2) res = (res * a) % mod;
        return res;
    }
    long long divide(long long a, long long b){
        a%=mod;
        b%=mod;
        return (a*power(b, mod-2)%mod)%mod;
    }
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n= prevRoom.size();
        mod = 1000000007;
        vector<vector<int>> tree(n);
        for(int i=1; i<n; i++){
            tree[prevRoom[i]].push_back(i);
        }
        vector<long long> fact(1e5+1);
        fact[0] = 1, fact[1] = 1;
        for(int i=2; i<=1e5; i++){
            fact[i] = (i*fact[i-1])%mod;
        }

        function<pair<long long, long long>(long long)> solve = [&](long long node)->pair<long long, long long>{
            long long totalWays=1;
            long long prodFact = 1;
            long long size=1;
            for(auto &child: tree[node]){
                auto [sizeChild, prod] = solve(child);
                totalWays*=prod;
                totalWays%=mod;
                size+=sizeChild;
                prodFact*=fact[sizeChild];
                prodFact%=mod;
            }
            totalWays*=divide(fact[size-1], prodFact);
            totalWays%=mod;
            return {size, totalWays};
        };
        return (int)solve(0).second;
    }
};