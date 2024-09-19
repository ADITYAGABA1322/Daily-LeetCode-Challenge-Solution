#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>

class Solution {
public:
    std::vector<int> diffWaysToCompute(const std::string& expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        std::vector<int> res;
        int n = expression.size();

        // Base case: if the expression is a single number, return it as the only result
        if (isNumber(expression)) {
            res.push_back(std::stoi(expression));
            memo[expression] = res;
            return res;
        }

        // Recursive case: split the expression at each operator
        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Recursively compute the results for the left and right subexpressions
                std::vector<int> left = diffWaysToCompute(expression.substr(0, i));
                std::vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results from the left and right subexpressions using the current operator
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else if (c == '*') res.push_back(l * r);
                    }
                }
            }
        }

        memo[expression] = res;
        return res;
    }

private:
    std::unordered_map<std::string, std::vector<int>> memo;

    bool isNumber(const std::string& s) {
        return std::all_of(s.begin(), s.end(), ::isdigit);
    }
};