class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> mp;
        int n=words.size();
        int ans=0;
        for(int i=0; i<n; i++){
            string rev=words[i];
            reverse(rev.begin(), rev.end());
            if(mp[rev]){
                ans++;
            }
            else{
                mp[words[i]]++;
            }
        }
        return ans;
    }
};