#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};
        
        string result;
        int i = 0;
        
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000, belowTwenty, tens) + thousands[i] + " " + result;
            }
            num /= 1000;
            i++;
        }
        
        while (result.back() == ' ') result.pop_back(); // Remove trailing spaces
        return result;
    }
    
private:
    string helper(int num, vector<string>& belowTwenty, vector<string>& tens) {
        if (num == 0) return "";
        else if (num < 20) return belowTwenty[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10, belowTwenty, tens);
        else return belowTwenty[num / 100] + " Hundred " + helper(num % 100, belowTwenty, tens);
    }
};