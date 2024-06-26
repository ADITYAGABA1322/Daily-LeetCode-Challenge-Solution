#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isPrefixAndSuffix(string& prefix, string& word) {
        if (word.size() < prefix.size()) {
            return false;
        }
        return word.substr(0, prefix.size()) == prefix && word.substr(word.size() - prefix.size()) == prefix;
    }
};