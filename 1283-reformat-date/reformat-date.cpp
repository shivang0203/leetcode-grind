class Solution {
public:
    string reformatDate(string date) {

        stringstream ss(date); 

        string dayStr, monthStr, yearStr, day;

        getline(ss, dayStr, ' '); 
        getline(ss, monthStr, ' ');
        getline(ss, yearStr, ' ');
        
        unordered_map<string, string> months = { 

        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}

        };

        if(dayStr.length() == 4){ 
            day = dayStr.substr(0,2);
        } 
        else { 
            day.push_back(dayStr[0]);
            day.insert(day.begin(), '0');
        }

        string result = yearStr + "-" + months[monthStr] + "-" + day;
        return result;

    }
};