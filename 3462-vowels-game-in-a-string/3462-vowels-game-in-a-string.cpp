class Solution {
public:
    bool doesAliceWin(string s) {
        // Count the total number of vowels in the string.
        int vowelCount = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++vowelCount;
            }
        }
        
        // If there's at least one vowel, Alice can make the first move.
        // This simplified approach assumes that having the ability to make a move
        // gives Alice the potential to win, without delving into the complexities
        // of optimal play and move sequences.
        return vowelCount > 0;
    }
};