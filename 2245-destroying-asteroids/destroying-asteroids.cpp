class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        long long m = mass;
        int n = ast.size();
        for (int i = 0; i < n; i++) {
            if (m >= ast[i]) {
                m += ast[i];
            } else
                return false;
        }
        return true;
    }
};