class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";

        string result;
        int n = word.size();
        int count = 1;

        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                count++;
                if (count == 10) {
                    result += "9";
                    result += word[i - 1];
                    count = 1;
                }
            } else {
                result += to_string(count);
                result += word[i - 1];
                count = 1;
            }
        }

        // Append the last character and its count
        result += to_string(count);
        result += word[n - 1];

        return result;
    }
};