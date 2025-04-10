class Solution {
public:
    long long solve(int index, bool tightBound, char digitLimit, string &valLimit, string &suffix, vector<vector<long long>> &dp){
        int sizeVal = valLimit.size();
        int sizeSuffix = suffix.size();

        if(sizeSuffix > sizeVal) return 0;

        if(dp[tightBound][index] >= 0){
            return dp[tightBound][index];
        }

        if((index + sizeSuffix) == sizeVal){
            return dp[tightBound][index] = tightBound ? suffix <= valLimit.substr(index) : 1;
        }

        long long ans = 0;
        char digitBound = tightBound ? min(digitLimit, valLimit[index]) : digitLimit;
        for(char d = '0'; d <= digitBound; d++){
            ans += solve(index+1, (tightBound && valLimit[index] == d), digitLimit, valLimit, suffix, dp);
        }
        return dp[tightBound][index] = ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string finishStr = to_string(finish);
        char digitLimit = '0' + limit;

        vector<vector<long long>> dp1(2, vector<long long>(finishStr.size(),-1));
        long long count1 =  solve(0, true, digitLimit, finishStr, s, dp1);

        vector<vector<long long>> dp2(2, vector<long long>(finishStr.size(),-1));
        long long count2 = solve(0, true, digitLimit, startStr, s, dp2);

        return count1 - count2;
    }
};