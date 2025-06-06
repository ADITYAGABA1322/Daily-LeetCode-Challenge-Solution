class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        
        // Count frequency of each character
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string paper = "";  // Result
        string t = "";      // Robot's string acting as a stack
        
        // Track the smallest remaining character
        char smallest = 'a';
        
        for (char c : s) {
            // Update counts
            count[c - 'a']--;
            
            // Add current character to t
            t.push_back(c);
            
            // Update the smallest remaining character
            while (smallest <= 'z' && count[smallest - 'a'] == 0) {
                smallest++;
            }
            
            // Pop characters from t to paper if they are <= smallest remaining
            while (!t.empty() && t.back() <= smallest) {
                paper.push_back(t.back());
                t.pop_back();
            }
        }
        
        // Add any remaining characters from t to paper
        while (!t.empty()) {
            paper.push_back(t.back());
            t.pop_back();
        }
        
        return paper;
    }
};