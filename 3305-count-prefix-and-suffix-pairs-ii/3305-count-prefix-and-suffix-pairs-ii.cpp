#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long count = 0;
        int n = words.size();
        
        // Function to check if str1 is both a prefix and suffix of str2
        auto isPrefixAndSuffix = [](const string& str1, const string& str2) -> bool {
            if (str1.length() > str2.length()) return false;
            return str2.substr(0, str1.length()) == str1 && str2.substr(str2.length() - str1.length()) == str1;
        };
        
        // Iterate through all pairs of strings
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Check if words[i] is both a prefix and suffix of words[j]
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};