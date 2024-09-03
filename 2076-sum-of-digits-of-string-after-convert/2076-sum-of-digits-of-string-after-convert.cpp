class Solution {
public:
    int getLucky(string s, int k) {
        // Convert each character to its numerical value and build a string
        string numericString = "";
        for (char ch : s) {
            numericString += to_string(ch - 'a' + 1);
        }

        // Apply digit sum transformations k times
        while (k-- > 0) {
            int digitSum = 0;
            for (char digit : numericString) {
                digitSum += digit - '0';
            }
            numericString = to_string(digitSum);
        }

        // Convert the final string to integer and return
        return stoi(numericString);
    }
};