class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            // Convert current value to string
            string number = to_string(nums[i]);
            string formed = "";
            for (int j = 0; j < number.size(); ++j) {
                formed = formed + (to_string(mapping[number[j] - '0']));
            }
            // Store the mapped value.
            int mappedValue = stoi(formed);
            // Push a pair consisting of mapped value and original value;s
            // index.
            storePairs.push_back({mappedValue, i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};