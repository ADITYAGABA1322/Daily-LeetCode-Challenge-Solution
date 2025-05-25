class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // Count occurrences of each word
        unordered_map<string, int> count;
        for (string word : words) {
            count[word]++;
        }
        
        int length = 0;
        bool central = false;
        
        for (auto& [word, freq] : count) {
            // If the word is a palindrome (same letter twice)
            if (word[0] == word[1]) {
                // Use even number of such words
                length += (freq / 2) * 4;
                
                // If there's an odd number of such palindromic words,
                // one can be used at the center
                if (freq % 2 == 1) {
                    central = true;
                }
            }
            // If it's not a palindrome, find its reverse
            else if (word[0] < word[1]) {  // Process each pair once
                string rev = word;
                reverse(rev.begin(), rev.end());
                
                if (count.find(rev) != count.end()) {
                    // Use min(count of word, count of reverse) pairs
                    length += min(freq, count[rev]) * 4;
                }
            }
        }
        
        // If there's at least one palindromic word with odd frequency,
        // we can use one in the middle
        if (central) length += 2;
        
        return length;
    }
};