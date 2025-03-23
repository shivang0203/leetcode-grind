class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n = p.size();
        int m = t.size();

        sort(p.begin(),p.end());
        sort(t.begin(),t.end());

        int idx=0;
        int c=0;
        int i=0;
        while(i<n && idx<m)
        {
            if(p[i]<=t[idx]){
                idx++;
                i++;
                c+=1;
            }
            else{
                idx++;
            }
        }
        return c;
    }
};