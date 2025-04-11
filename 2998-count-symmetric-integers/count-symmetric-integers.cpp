class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
        string s= to_string(i);
        int len = s.length();
        if(len%2!=0) continue;
            int half = len/2;
            int leftSum=0;int rightSum=0;
            for(int i=0;i<half;i++){
                leftSum+=s[i]-'0';
                rightSum += s[i+half]-'0';
            }
            if(leftSum == rightSum){
                count++;
            }
        }
        return count;
    }
};