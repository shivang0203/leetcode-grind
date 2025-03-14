class Solution {
public:
    int solve(int eat,vector<int> &piles,int h){
        int time=0;
        for(auto it:piles){
            time +=it/eat + (it%eat!=0);
            if(time>h)return 0;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right= *max_element(piles.begin(),piles.end());
        int result=0;
        while(left<=right){
            int mid= left +(right-left)/2;

            if(solve(mid,piles,h)){
                result = mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return result;
    }
};