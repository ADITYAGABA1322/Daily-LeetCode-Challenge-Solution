class Solution {
public:
    int minLength(string s) {
        // Continue processing while "AB" or "CD" substrings exist
        while (s.find("AB") != -1 || s.find("CD") != -1) {
            if (s.find("AB") != -1) {
                // Remove all occurrences of "AB"
                s.erase(s.find("AB"), 2);
            } else if (s.find("CD") != -1) {
                // Remove all occurrences of "CD"
                s.erase(s.find("CD"), 2);
            }
        }

        return s.length();
    }
};