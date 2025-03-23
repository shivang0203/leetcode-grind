class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        while (name.size() > 0 && typed.size() > 0) {
            char x = name[0];
            int a = 0, b = 0, i = 0, j = 0;
            while (i < name.size() && x == name[i]) {
                a++;
                i++;
            }
            while (j < typed.size() && x == typed[j]) {
                b++;
                j++;
            }
            if (a > b)
                return false;
            name.erase(0, a);
            typed.erase(0, b);
        }
        return (name.empty() && typed.empty());
    }
};