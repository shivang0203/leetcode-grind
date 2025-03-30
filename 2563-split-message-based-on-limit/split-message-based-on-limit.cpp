class Solution {
public:
    int isValidTotalPart(string& message, int limit, int numberOfDigit) {
        int a = 0, i=0;
        limit = limit - 3 - numberOfDigit; 
        if(limit<=0) return 0;
        while(i<message.size()) {
            a++; 
            int l = limit - to_string(a).size(); 
            if(l<=0) return 0; 
            i+=l; 
        }
        return a; 
    }

    vector<string> splitMessage(string message, int limit) {
        int b = 0;
        for(int numberOfDigit=1; numberOfDigit<=5; numberOfDigit++) {
            int totalPart = isValidTotalPart(message,limit, numberOfDigit);
            if(totalPart>0 && to_string(totalPart).size()==numberOfDigit) { 
                b=totalPart;
                break;
            }
        }

        if(b==0) return {};
        vector<string> ans(b); 
        limit = limit - 3 - to_string(b).size();
        int i=0;
        for(int a=1; a<=b; a++) {
            int l = limit - to_string(a).size();
            ans[a-1] = message.substr(i, l) + "<" + to_string(a) + "/" + to_string(b) + ">";
            i+=l;
        }

        return ans;
    }
};