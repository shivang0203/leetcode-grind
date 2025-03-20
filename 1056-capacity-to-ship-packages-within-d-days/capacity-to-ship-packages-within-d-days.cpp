class Solution {
public:
    int solve(vector<int>& weights, int days, int capacity) {
        int temp = 0;
        int day = 1; 
        
        for (int weight : weights) {
            if (temp + weight > capacity) {
                day++;
                temp = 0;
            }
            temp += weight;
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int curr = right; 

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int temp = solve(weights, days, mid);

            if (temp <= days) { 
                curr = mid;      
                right = mid - 1;  
            } else {
                left = mid + 1;  
            }
        }

        return curr;
    }
};