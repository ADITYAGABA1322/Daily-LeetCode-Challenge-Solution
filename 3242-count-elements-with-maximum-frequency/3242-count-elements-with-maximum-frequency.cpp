#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int max_freq = 0;
        for (auto& pair : freq) {
            max_freq = max(max_freq, pair.second);
        }

        int total = 0;
        for (auto& pair : freq) {
            if (pair.second == max_freq) {
                total += pair.second;
            }
        }

        return total;
    }
};