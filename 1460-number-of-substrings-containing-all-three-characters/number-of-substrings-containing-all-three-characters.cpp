class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.size();
        int count=0;
        vector<int> lastSeen(3,-1);
        for(int i=0;i<n;i++){
            lastSeen[s[i]-'a']=i;
            int mini = min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
            if(mini!=-1){
                count +=1+mini;
            }
        }
        return count;
    }
};