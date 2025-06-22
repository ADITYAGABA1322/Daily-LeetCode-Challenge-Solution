class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;  // grouped string
        int n = s.size();
        int curr = 0;  // starting index of each group
        // split string
        while (curr < n) {
            res.push_back(s.substr(curr, k));
            curr += k;
        }
        // try to fill in the last group
        res.back() += string(k - res.back().length(), fill);
        return res;
    }
};