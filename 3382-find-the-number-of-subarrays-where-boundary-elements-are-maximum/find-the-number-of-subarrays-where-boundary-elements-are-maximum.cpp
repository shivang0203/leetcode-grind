class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        stack<int> st;
        long long ans = 0;
        int ctn = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && st.top() < nums[i]) {
                if (last == -1 || last == st.top()) ctn++;
                else ctn = 1;
                last = st.top();
                ans += ctn;
                st.pop();
            }
            st.push(nums[i]);
            last = -1;
            ctn = 0;
        }
        while (!st.empty()) {
            if (last == -1 || last == st.top()) ctn++;
                else ctn = 1;
                last = st.top();
                ans += ctn;
                st.pop();
            }
            return ans;
        }
    };