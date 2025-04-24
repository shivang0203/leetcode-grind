class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        vector<int> freq(1000001, 0);
        int s = 0, e = 0;
        int mini = INT_MAX;
        while(e < n){
            freq[cards[e]]++;
            if(freq[cards[e]] > 1) {
                mini = min(mini, e - s + 1);
                while(s < e && freq[cards[e]] > 1){
                    freq[cards[s]]--;
                    s++;
                }
                mini = min(mini, e - s + 2);
            }
            e++;
        }
        return (mini == INT_MAX)? -1 : mini;
    }
};