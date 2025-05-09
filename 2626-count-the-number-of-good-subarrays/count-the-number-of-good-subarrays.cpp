class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        int srt = 0;
        map <int, int> hash;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += hash[nums[i]];
            hash [nums[i]] ++;
            while (cur >= k) {
                res += (n - i);
                cur -= hash[nums[srt]] - 1;
                hash[nums[srt]] --;            
                srt ++;
            }
        }
        return res;
    }
};