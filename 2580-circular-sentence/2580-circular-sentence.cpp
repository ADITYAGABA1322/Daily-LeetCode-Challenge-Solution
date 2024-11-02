class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Use the split function to store the words in a vector.
        stringstream ss(sentence);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        int n = words.size();

        // Start comparing from the last character of the last word.
        char last = words[n - 1].back();

        for (int i = 0; i < n; i++) {
            // If this character is not equal to the first character of current
            // word, return false.
            if (words[i].front() != last) return false;
            last = words[i].back();
        }

        return true;
    }
};