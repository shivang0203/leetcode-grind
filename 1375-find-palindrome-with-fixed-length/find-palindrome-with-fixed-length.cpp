#define ll long long
class Solution {
    ll nthpalindrome(int n, int len, int exp){
        ll n1 = pow(10,exp);
        ll n2 = n1+(n-1);
        string s1 = to_string(n2);
        string s2 = "";
        for(int i=1; i<=(len/2); i++){
            s2+=s1[i-1];
        }
        reverse(s2.begin(), s2.end());
        s1=s1+s2;
        ll ans = stoll(s1);
        return ans;
    }
public:
    vector<ll> kthPalindrome(vector<int>& v, int len) {
        int n = v.size();
        vector<ll> ans(n,0);
        int exp;
        if(len%2){
            exp=len/2;
        }else{
            exp=len/2-1;
        } 
        int lim = 9*pow(10,exp);
        for(int i=0; i<n; i++){
            int nth = v[i];
            if(nth>lim) ans[i]=-1;
            else ans[i]=nthpalindrome(nth,len,exp);
        }
        return ans;
    }
};