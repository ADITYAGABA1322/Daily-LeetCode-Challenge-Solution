#include <vector>
#include <string>
#include <algorithm> // For std::sort

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> heightNamePairs;

        // Pair each height with the corresponding name
        for (int i = 0; i < n; ++i) {
            heightNamePairs.push_back({heights[i], names[i]});
        }

        // Sort the pairs in descending order of height
        sort(heightNamePairs.begin(), heightNamePairs.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first; // Descending order
        });

        // Extract the names from the sorted pairs
        vector<string> sortedNames;
        for (auto& pair : heightNamePairs) {
            sortedNames.push_back(pair.second);
        }

        return sortedNames;
    }
};