class Spreadsheet {
public:
    unordered_map<string, int> mpp;
    Spreadsheet(int rows) {}
    void setCell(string cell, int value) { 
        mpp[cell] = value; 
    }
    void resetCell(string cell) { 
        mpp[cell] = 0; 
    }

    int getValue(string s) {
        s = s.substr(1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') {
                string s1 = s.substr(0, i), s2 = s.substr(i + 1);
                int left = s1[0] >= 'A' && s1[0] <= 'Z' ? mpp[s1] : stoi(s1);
                int right = s2[0] >= 'A' && s2[0] <= 'Z' ? mpp[s2] : stoi(s2);
                return left + right;
            }
        }
        return 0;
    }
};