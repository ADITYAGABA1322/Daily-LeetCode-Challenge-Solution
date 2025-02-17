class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> seen;

        // Sort characters to handle duplicates efficiently
        sort(tiles.begin(), tiles.end());

        // Find all unique sequences and their permutations
        return generateSequences(tiles, "", 0, seen) - 1;
    }

private:
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }

        int result = 1;
        for (int num = 2; num <= n; num++) {
            result *= num;
        }
        return result;
    }

    int countPermutations(string& seq) {
        // Count frequency of each character
        int charCount[26] = {0};
        for (char ch : seq) {
            charCount[ch - 'A']++;
        }

        // Calculate permutations using factorial formula
        int total = factorial(seq.length());
        for (int count : charCount) {
            if (count > 1) {
                total /= factorial(count);
            }
        }
        return total;
    }

    int generateSequences(string& tiles, string current, int pos,
                          unordered_set<string>& seen) {
        if (pos >= tiles.length()) {
            // If new sequence found, count its unique permutations
            if (seen.insert(current).second) {
                return countPermutations(current);
            }
            return 0;
        }

        // Try including and excluding current character
        return generateSequences(tiles, current, pos + 1, seen) +
               generateSequences(tiles, current + tiles[pos], pos + 1, seen);
    }
};