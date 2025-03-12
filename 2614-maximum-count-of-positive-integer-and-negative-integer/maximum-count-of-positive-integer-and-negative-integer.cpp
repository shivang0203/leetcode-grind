class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int maxi=INT_MIN;
        int neg=0;
        int pos=0;
        for(auto it: nums){
            if(it==0)continue;
            else if(it<0)neg++;
            else if(it>0)pos++;
            maxi = max(pos,neg);
        }
        return maxi!=INT_MIN ? maxi:0;
    }

};