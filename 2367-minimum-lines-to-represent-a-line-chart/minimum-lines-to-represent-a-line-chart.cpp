class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int num_lines = 0;
        int i = 0;
        optional<int64_t> prev_dx, prev_dy;
        while(i + 1 < stockPrices.size()) {
            int j = i+1;
            int64_t dx = stockPrices[j][0] - stockPrices[i][0];
            int64_t dy = stockPrices[j][1] - stockPrices[i][1];
            if(!prev_dx.has_value()) {
                num_lines++;
            } else {
                int64_t target_a = dx * prev_dy.value();
                int64_t target_b = dy * prev_dx.value();
                if(target_a != target_b) {
                    num_lines++;
                }
            }
            prev_dx = dx;
            prev_dy = dy;
            i = j;
        }
        return num_lines;
    }
};