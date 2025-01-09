class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            count += hasPrefix(word, pref);
        }
        return count;
    }

private:
    // Returns 1 if str has pref as prefix, 0 otherwise
    int hasPrefix(string& str, string& pref) {
        int itr;
        // Compare characters until we reach the end of either string
        for (itr = 0; itr < str.length() && itr < pref.length(); itr++) {
            if (str[itr] != pref[itr]) {
                return 0;  // Mismatch found
            }
        }

        // Check if we've matched the entire prefix
        if (itr != pref.length()) {
            return 0;  // str is shorter than pref
        }
        return 1;
    }
};