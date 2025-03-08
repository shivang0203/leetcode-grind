class Solution {
public:
    void backtrack(int idx,vector<int> &nums,vector<vector<int>> &res){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            backtrack(idx+1,nums,res);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0,nums,res);
        return res;
    }
};