#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    static bool compare(const std::string &a, const std::string &b) {
        return a + b > b + a;
    }

    std::string largestNumber(std::vector<int>& nums) {
        // Convert numbers to strings
        std::vector<std::string> numStrs;
        for (int num : nums) {
            numStrs.push_back(std::to_string(num));
        }

        // Sort the strings using the custom comparator
        std::sort(numStrs.begin(), numStrs.end(), compare);

        // Handle the case where the largest number is "0"
        if (numStrs[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings
        std::string result;
        for (const std::string &numStr : numStrs) {
            result += numStr;
        }

        return result;
    }
};