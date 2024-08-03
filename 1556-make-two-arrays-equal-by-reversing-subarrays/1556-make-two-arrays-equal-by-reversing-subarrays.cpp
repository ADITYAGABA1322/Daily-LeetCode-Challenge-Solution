#include <vector>
#include <algorithm>

class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());
        return target == arr;
    }
};