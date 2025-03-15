class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0,right= n-1;
        int maxi=0;
        while(left<=right){
            int h = min(height[left],height[right]);
            int w = abs(right-left);
            int hold =h*w;
            maxi = max(maxi,hold);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};