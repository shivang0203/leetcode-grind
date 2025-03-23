class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        int n=speed.size();
        vector<pair<int,double>>cars(n);
        for(int i=0;i<n;i++){
            cars[i]={position[i],(double)(target-position[i])/speed[i]};
        }
        sort(cars.begin(),cars.end());
        stack<double>s;
        for(int i=n-1;i>=0;i--){
            if(s.empty() || !(cars[i].second <=s.top())) s.push(cars[i].second);
        }
        return s.size();
    }
};