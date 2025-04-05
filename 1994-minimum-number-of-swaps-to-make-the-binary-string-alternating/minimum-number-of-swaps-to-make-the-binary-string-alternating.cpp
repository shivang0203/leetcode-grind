class Solution {
public:

    int minSwaps(string s) {
        int n=s.size();
        int one_sz=n/2,zero_sz=n/2,one=0,zero=0;
        if(n%2!=0){
            one_sz++;
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]=='1') one++;
            }else{
                if(s[i]=='0') zero++;
            }
        }
        int mini=INT_MAX;
        if((one_sz-one)==(zero_sz-zero)){
            mini=min(mini,one_sz-one);
        }
        if(one==zero){
            mini=min(mini,one);
        }
         if(mini==INT_MAX){
            return -1;
         }
        return mini;
    }
};