class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> temp(questions.size()+1,0);
        for(int i=questions.size()-1 ; i >= 0 ; i--){
            long long temp1 = temp[i+1];
            long long temp2;
            if(i+questions[i][1] >= questions.size()){
                temp2 =  questions[i][0];
            }else{
                temp2 = questions[i][0] + temp[i+questions[i][1]+1];
            }

            temp[i] = max(temp1,temp2);
           
        }

        return temp[0];
    }
};