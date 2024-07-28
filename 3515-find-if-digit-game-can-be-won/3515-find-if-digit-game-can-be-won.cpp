#include <vector>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumSingleDigit = 0, sumDoubleDigit = 0;

        // Calculate the sums of single-digit and double-digit numbers
        for (int num : nums) {
            if (num >= 1 && num <= 9) {
                sumSingleDigit += num;
            } else if (num >= 10 && num <= 99) {
                sumDoubleDigit += num;
            }
        }

        // Alice wins if the sum of her chosen numbers is strictly greater than the sum of Bob's numbers
        return sumSingleDigit > sumDoubleDigit || sumDoubleDigit > sumSingleDigit;
    }
};