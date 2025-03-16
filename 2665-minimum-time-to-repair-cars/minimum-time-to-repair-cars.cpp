class Solution {
public:
    bool solve(long long res,vector<int>& ranks, int cars){
        long long cnt=0;
        for(int i=0;i<ranks.size();i++){
            cnt+=sqrt((res*1.0)/ranks[i]);
        }

        return cnt>=cars*1LL;
    }
    long long repairCars(vector<int>& ranks, int cars) {

        long long low=1;
        long long high=*max_element(ranks.begin(),ranks.end())*1LL*cars*cars;

        long long ans=high;

        while(low<=high){
            long long mid=(low+high)/2;
            if(solve(mid,ranks,cars)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};