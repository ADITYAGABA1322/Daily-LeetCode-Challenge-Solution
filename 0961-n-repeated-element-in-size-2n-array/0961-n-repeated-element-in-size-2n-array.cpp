class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int n : nums) {
            mp[n]++;
        }

        for (auto it : mp) {
            if (it.second > 1) {
                return it.first;  // return the number, not count
            }
        }

        return -1; // safety
    }
};