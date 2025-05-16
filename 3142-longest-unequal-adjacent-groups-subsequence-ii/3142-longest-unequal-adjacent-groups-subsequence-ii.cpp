class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        
        // dp[i] = length of longest valid subsequence ending at index i
        vector<int> dp(n, 1);
        
        // prev[i] = previous index in the optimal subsequence
        vector<int> prev(n, -1);
        
        // Calculate Hamming distance between two strings
        auto hammingDistance = [](const string& a, const string& b) -> int {
            if (a.size() != b.size()) return -1; // Different lengths
            
            int distance = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) distance++;
            }
            return distance;
        };
        
        // Fill dp array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Check all three conditions:
                // 1. Different groups
                // 2. Same length words
                // 3. Hamming distance exactly 1
                if (groups[i] != groups[j] && 
                    hammingDistance(words[i], words[j]) == 1 &&
                    dp[j] + 1 > dp[i]) {
                    
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        
        // Find index with maximum length
        int maxLength = 0, maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                maxIndex = i;
            }
        }
        
        // Reconstruct the result
        vector<string> result;
        while (maxIndex != -1) {
            result.push_back(words[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        
        // Reverse to get correct order
        reverse(result.begin(), result.end());
        return result;
    }
};