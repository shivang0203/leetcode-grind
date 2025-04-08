class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=nums.size()-1;i>=0;i--){
           if(mp.find(nums[i])==mp.end()){
             mp[nums[i]]=1;
           }
           else{
            break;
           }
        }
        return (nums.size()-mp.size()==0)? 0 : int(ceil(double(nums.size()-mp.size())/3));
    }
};